#include <iostream>
#include "ap_axi_sdata.h"
#include "hls_stream.h"
#include "hls_math.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include "getPhaseMap.h"

using namespace std;

#define REG_CTRL(offset, scale, mode) ((offset << 16) + (scale << 2) + mode)

void gen_groundtruth(uint16* groundTruth, uint16* dcsMap, unsigned int regCtrl, int threshold) {

	int mode = regCtrl & 0x3;
	int scale_en = regCtrl & 0x4;
	unsigned short offset = regCtrl >> 16;

	//Generate expected output
	for (int i = 0; i < NUMPIX; i++) {
		int12 dcs0 = (int12)(dcsMap[i]);
		groundTruth[i] = dcs0;
	}

	for (int i = NUMPIX; i < 2*NUMPIX; i++) {
		int12 dcs0 = (int12)(dcsMap[i-NUMPIX]);
		int12 dcs2 = (int12)(dcsMap[i]);
		if (mode == MODE_RAW) {
			groundTruth[i] = dcs2;
		} else {
			groundTruth[i] = dcs2 - dcs0;
		}
	}

	for (int i = 2*NUMPIX; i < 3*NUMPIX; i++) {
		int12 dcs1 = (int12)(dcsMap[i]);
		groundTruth[i] = dcs1;
	}

	uint16 amp_max;
	amp_max = 0;

	int i2 = 3*NUMPIX;
	for (int i = 3*NUMPIX; i < 4*NUMPIX; i++) {
		int12 dcs0 = (int12)(dcsMap[i-3*NUMPIX]);
		int12 dcs2 = (int12)(dcsMap[i-2*NUMPIX]);
		int12 dcs1 = (int12)(dcsMap[i-NUMPIX]);
		int12 dcs3 = (int12)(dcsMap[i]);
		int16 dcs31 = (dcs3 - dcs1);
		int16 dcs20 = (dcs2 - dcs0);
		int16_3 dcs31_fixed, dcs20_fixed;
		int16_3 phase_fixed;
		uint16 phaseInt;
		uint16 tmp;
		dcs31_fixed.V = dcs31.V;
		dcs20_fixed.V = dcs20.V;
		phase_fixed = hls::atan2(dcs31_fixed, dcs20_fixed);
		phase_fixed = phase_fixed + int16_3(M_PI);
		phaseInt.V = phase_fixed.V;
		phaseInt = phaseInt * 32767 / 51471;

		int32 amp = hls::sqrt(dcs31*dcs31 + dcs20*dcs20);

		if (mode == MODE_RAW) {
			groundTruth[i] = dcs3;
		} else if (mode == MODE_AMP) {
			groundTruth[i] = (uint16) amp;
		} else if (mode == MODE_PHASE) {
			if (amp < threshold) {
				groundTruth[i] = (uint16) 0xFFFF;
			} else {
				groundTruth[i] = (phaseInt + offset) & 0x07FFF;
			}
		}
		if (amp > amp_max) {
			amp_max = amp;
		}
	}
	std::cout << "amp max: " << amp_max << endl;

	if (mode == MODE_AMP && scale_en) {
		uint16 tmp;
		i2 = 4*NUMPIX;
		for (int i = 3*NUMPIX; i < 4*NUMPIX; i++) {
			uint16 scaled = groundTruth[i] *255 / amp_max;
			tmp = (tmp >> 8) + (scaled << 8);
			if (i%2) {
				groundTruth[i2] = tmp;
				i2++;
			}
		}
	} else if (mode == MODE_AMP && scale_en == 0) {
		uint16 tmp;
		i2 = 4*NUMPIX;
		for (int i = 3*NUMPIX; i < 4*NUMPIX; i++) {
			uint16 amp = groundTruth[i];
			tmp = (tmp >> 8) + (amp << 8);
			if (i%2) {
				groundTruth[i2] = tmp;
				i2++;
			}
		}
	}

}

void reset_output(uint16* framebuffer, uint16* groundtruth) {
	for (int i = 0; i < 5*NUMPIX; i++) {
		groundtruth[i] = 0;
		framebuffer[i] = 0;
	}
}

int check_output(uint16* groundTruth, uint16* framebuffer, int scale) {
	int test_pass = 1;

	//Check hw result against expected output
	for (int i = 0; i < 4*NUMPIX; i++) {
		if (framebuffer[i] != groundTruth[i]) {
			printf("result[%d] not match: result %d sim %d\n", i, int(groundTruth[i]), int(framebuffer[i]));
			test_pass = 0;
		}
	}

	if (scale) {
		for (int i = 4*NUMPIX; i < 5*NUMPIX; i++) {
			if (framebuffer[i] != groundTruth[i]) {
				printf("result[%d] not match: result %d sim %d\n", i, int(groundTruth[i]), int(framebuffer[i]));
				test_pass = 0;
			}
		}
	}

	return test_pass;
}

void writeFile(const char* FN, uint16* buffer, int sz) {
	//dump result to file
	ofstream outdata;
	outdata.open(FN, ios::out|ios::binary);
	if (!outdata.is_open()) {
		printf("Cannot open output image\n");
	}

	for (int i = 0; i < sz; i++) {
		unsigned short phase_uint16 = buffer[i].to_int();
		outdata.write((char*)&phase_uint16, sizeof(phase_uint16));
	}

	outdata.close();

	cout << sz << " data write to " << FN << "\n";
}

int main() {
	static uint16 dcsMap[NUMPIX*4];
	static uint16 framebuffer[NUMPIX*5];
	static uint16 groundTruth[NUMPIX*5];
	volatile uint16 *port0, *port1;
	int threshold = -1;

	int test_pass = 1;

	ifstream indata;
	indata.open(INFILE, ios::in|ios::binary);
	if (!indata.is_open()) {
		printf("Cannot open input image\n");
		return -1;
	}

	indata.seekg (0, indata.end);
	int length = indata.tellg();
	printf("File size = %d (bytes)\n", length);
	indata.seekg (0, indata.beg);

	for (int i = 0 ; i < NUMPIX*4; i++) {
		unsigned short dcs_uint16;
		indata.read((char*) &dcs_uint16, sizeof(dcs_uint16));
		dcsMap[i] = dcs_uint16;
	}

	indata.close();

	port0 = framebuffer;
	port1 = framebuffer;

	unsigned int regCtrl;
	int mode, offset, scale;
	cout << "TEST01: Save raw data\n";
	mode = MODE_RAW;
	offset = 0;
	scale = 0;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = -1;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST01 FAILED";
		return -1;
	}

	cout << "TEST02: Save amplitude image, clamping\n";
	mode = MODE_AMP;
	offset = 0;
	scale = 0;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = -1;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST02 FAILED";
		return -1;
	}
	writeFile(OUTFILE_AMP_CLAMP, framebuffer+4*NUMPIX, NUMPIX/2);


	cout << "TEST03: Save amplitude image, scaling\n";
	mode = MODE_AMP;
	offset = 0;
	scale = 1;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = -1;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST03 FAILED";
		return -1;
	}
	writeFile(OUTFILE_AMP, framebuffer+4*NUMPIX, NUMPIX/2);

	cout << "TEST04: Save phase image, offset = 0\n";
	mode = MODE_PHASE;
	offset = 0;
	scale = 0;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = -1;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST04 FAILED";
		return -1;
	}
	writeFile(OUTFILE_PHASE, framebuffer+3*NUMPIX, NUMPIX);

	return 0;

	cout << "TEST05: Save phase image, offset = pi\n";
	mode = MODE_PHASE;
	offset = 32768;
	scale = 0;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = -1;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST05 FAILED";
		return -1;
	}
	writeFile(OUTFILE_PHASE, framebuffer+3*NUMPIX, NUMPIX);

	cout << "TEST06: Save phase image, offset = 2pi\n";
	mode = MODE_PHASE;
	offset = 65535;
	scale = 0;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = -1;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST06 FAILED";
		return -1;
	}
	writeFile(OUTFILE_PHASE, framebuffer+3*NUMPIX, NUMPIX);

	cout << "TEST07: Save phase image, offset = 0, threshold = 100\n";
	mode = MODE_PHASE;
	offset = 0;
	scale = 0;
	regCtrl = REG_CTRL(offset, scale, mode);
	threshold = 100;
	reset_output(framebuffer, groundTruth);
	gen_groundtruth(groundTruth, dcsMap, regCtrl, threshold);
	getPhaseMap2(regCtrl, threshold, dcsMap, port0, port1);
	test_pass = check_output(groundTruth, framebuffer, scale);
	if (test_pass == 0) {
		cout << "TEST06 FAILED";
		return -1;
	}
	writeFile(OUTFILE_PHASE, framebuffer+3*NUMPIX, NUMPIX);

	if (!test_pass) return -1;

//	printf("Sim success, check result in %s\n", OUTFILE);
	return !(test_pass);
}


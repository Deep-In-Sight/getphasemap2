#include "ap_axi_sdata.h"
#include "hls_math.h"
#include "stdio.h"
#include "ap_fixed.h"
#include "getPhaseMap.h"
#include <iostream>

uint16 get_L3(int mode, uint16 offset, int thresh, int16 dcs31, int16 dcs20);
uint16 get_L4(uint16 amp16_1, uint16 amp16_2, uint1 scale_en, uint16 amp_max); 

/*
 * calculate a phase map from 4 dcs maps
 * L0: save dcs0 to framebuffer02[0]
 * L1: read dcs0 and save dcs2-dcs0 to framebuffer02[1]
 * L2: save dcs1 to framebuffer13[0]
 * L3: read dcs1, read (dcs2-dcs0), save phase to framebuffer13[1]
 * dcs stream is 12bit signed integer, packed to 16bit zero padded integer
 * port0: read only, port1: read-write
 * */
void getPhaseMap2(unsigned int regCtrl, 
		int threshold,
		volatile uint16* dcs_in, 
		volatile uint16* port0, 
		volatile uint16* port1) {

#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=regCtrl
#pragma HLS INTERFACE s_axilite port=threshold

DO_PRAGMA(HLS INTERFACE axis port=dcs_in depth=SIM_STREAM_DEPTH)
DO_PRAGMA(HLS INTERFACE m_axi port=port0 offset=slave bundle=port0 depth=READ_DEPTH max_widen_bitwidth=AXI_WIDTH max_write_burst_length=AXI_BURST max_read_burst_length=AXI_BURST)
DO_PRAGMA(HLS INTERFACE m_axi port=port1 offset=slave bundle=port1 depth=READ_DEPTH max_widen_bitwidth=AXI_WIDTH max_write_burst_length=AXI_BURST max_read_burst_length=AXI_BURST)


	int12 dcs0, dcs1, dcs2, dcs3, dcs3_2, dcs1_2;
	int16 dcs20, dcs31, dcs20_2, dcs31_2;

	uint16 L1_result, L3_result, amp_max;
	uint16 amp16_1, amp16_2, amp8x2;

	int mode = regCtrl & 0x03;
	uint1 amp_scale_en = uint1((regCtrl >> 2) & 0x01);
	uint16 offset = uint16((regCtrl >> 16) & 0xFFFF);

	L0: for (int i = 0; i < NUMPIX; i++) {
#pragma HLS PIPELINE
		dcs0 = dcs_in[i];
		port1[i] = dcs0;
	}

	L1: for (int i = NUMPIX; i < 2*NUMPIX; i++) {
#pragma HLS PIPELINE
		dcs2 = (int12) dcs_in[i];
		dcs0 = (int12) port0[i-NUMPIX];
		dcs20 = (int16) (dcs2 - dcs0);
		if (mode == MODE_RAW) {
			L1_result = dcs2;
		} else {
			L1_result = dcs20;
		}
		port1[i] = L1_result;
	}

	L2: for (int i = 2*NUMPIX; i < 3*NUMPIX; i++) {
#pragma HLS PIPELINE
		dcs1 = dcs_in[i];
		port1[i] = dcs1;
	}

	amp_max = 0;

	L3: for (int i = 3*NUMPIX; i < 4*NUMPIX; i++) {
#pragma HLS PIPELINE
		dcs3 = (int12) dcs_in[i];
		dcs20 = (int16)port0[i-2*NUMPIX];
		dcs1 = (int12) port1[i-NUMPIX];
		dcs31 = (int16) (dcs3 - dcs1);

		if (mode == MODE_RAW) {
			L3_result = dcs3;
		} else if (mode == MODE_AMP || mode == MODE_PHASE) {
			L3_result = get_L3(mode, offset, threshold, dcs31, dcs20);
		} else {
			L3_result = 0;
		}

		if (L3_result > amp_max) {
			amp_max = L3_result;
		} else {
			amp_max = amp_max;
		}

		port1[i] = L3_result;
	}

    int i2 = 4*NUMPIX;
    if (mode == MODE_AMP) {
    	L4: for (int i = 3*NUMPIX; i < 4*NUMPIX; i+=2) {
#pragma HLS PIPELINE
    		amp16_1 = port0[i];
    		amp16_2 = port0[i + 1];
    		amp8x2 = get_L4(amp16_1, amp16_2, amp_scale_en, amp_max);
    		port1[i2] = amp8x2;
    		i2++;
    	}
    }
	return;
}

uint16 getPhase(int16 dcs31, int16 dcs20){
#pragma HLS PIPELINE
	int16_3 Q,I, phase;
	uint16 phaseInt;
	Q.V = dcs31.V;
	I.V = dcs20.V;
	phase = hls::atan2(Q, I);
	phase = phase + int16_3(M_PI);//dangerous
	phaseInt.V = phase.V;
	//leave MSB for amplitude masking
	phaseInt = phaseInt * 32767 / 51471; //51471 = 2pi*2^13, scale from 0:51471 to 0:32767, easier for phase wrap

	return phaseInt;
}

uint16 getAmp(int16 dcs31, int16 dcs20) {
#pragma HLS PIPELINE
	int32 amp;

	amp = dcs31*dcs31 + dcs20*dcs20;
	amp = hls::sqrt(amp);

	return amp;
}

uint16 get_L3(int mode, uint16 offset, int thresh, int16 dcs31, int16 dcs20) {
#pragma HLS PIPELINE
	uint16 amp;
	uint16 phase, phaseShifted, phaseMasked;
       
	amp = getAmp(dcs31, dcs20);
	phase = getPhase(dcs31, dcs20);
    phaseShifted = (phase + offset) & 0x07FFF;
	if (amp < thresh) {
		phaseMasked = 0xFFFF;
	} else {
		phaseMasked = phaseShifted;
	}
	if (mode == MODE_AMP) {
		return amp;
	} else {
		return phaseMasked;
	}
}

uint16 clamp(uint16 val) {
#pragma HLS PIPELINE
	uint16 ret;
	if (val > 255) {
		ret = 255;
	} else {
		ret = val;
	}
	return ret;
}

uint16 scale(uint16 val, uint16 max) {
#pragma HLS PIPELINE
	uint16 ret;
	ret = (val * 255) / max;
	return ret;
}

uint16 get_L4(uint16 amp16_1, uint16 amp16_2, uint1 scale_en, uint16 amp_max) {
#pragma HLS PIPELINE
	uint16 amp1_scaled, amp2_scaled, amp1_clamped, amp2_clamped;
	uint16 amp8x2;
	if (scale_en == 1) {
		amp1_scaled = scale(amp16_1, amp_max);
		amp2_scaled = scale(amp16_2, amp_max);
		amp8x2 = (amp2_scaled << 8) + amp1_scaled;
	} else {
		amp1_clamped = clamp(amp16_1);
		amp2_clamped = clamp(amp16_2);
		amp8x2 = (amp2_clamped << 8) + amp1_clamped;
	}
	return amp8x2;
}	

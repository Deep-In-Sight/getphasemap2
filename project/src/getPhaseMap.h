#ifndef _GETPHASEMAP_
#define _GETPHASEMAP_

//#define DBG_PRINT printf("%s %d\n", __FUNCTION__, __LINE__)
#define DBG_PRINT

#define PRAGMA_SUB(x) _Pragma (#x)
#define DO_PRAGMA(x) PRAGMA_SUB(x)

#define QUICKTEST 0
#if QUICKTEST
#define IMG_W 				32
#define IMG_H 				24
#define SIM_STREAM_DEPTH 	3072
#define SIM_AXI_DEPTH02		1536
#define SIM_AXI_DEPTH13		2304
#define READ_DEPTH			3840
#define WRITE_DEPTH			3840
#define AXI_BURST 			16
#define AXI_WIDTH			32
#define INFILE 				"../../../data/DCS_frame_crop.bin"
#define OUTFILE_RAW			"../../../data/raw_crop_fixed.bin"
#define OUTFILE_AMP			"../../../data/amp_crop_fixed.bin"
#define OUTFILE_AMP_CLAMP	"../../../data/amp_clamp_crop_fixed.bin"
#define OUTFILE_PHASE		"../../../data/phase_crop_fixed.bin"
#else
#define IMG_W 				640
#define IMG_H 				480
#define SIM_STREAM_DEPTH 	1228800
#define SIM_AXI_DEPTH02		614400
#define SIM_AXI_DEPTH13		921600
#define READ_DEPTH			1536000
#define WRITE_DEPTH			1536000
#define AXI_BURST 			32
#define AXI_WIDTH			32
#define INFILE 				"../../../data/DCS_frame_20210707_173908.bin"
#define OUTFILE_RAW			"../../../dataraw_20210707_173908_fixed.bin"
#define OUTFILE_AMP			"../../../data/amp_20210707_173908_fixed.bin"
#define OUTFILE_AMP_CLAMP	"../../../data/amp_clamp_20210707_173908_fixed.bin"
#define OUTFILE_PHASE		"../../../data/phase_20210707_173908_fixed.bin"
#endif
#define NUMPIX (IMG_W*IMG_H)

typedef ap_uint<1> 		uint1;
typedef ap_uint<3> 		uint3;
typedef ap_uint<16> 	uint16;
typedef ap_uint<17> 	uint17;
typedef ap_uint<32> 	uint32;
typedef ap_uint<33> 	uint33;
typedef ap_int<16> 		int16;
typedef ap_int<12> 		int12;
typedef ap_int<13> 		int13;
typedef ap_int<32> 		int32;
typedef ap_fixed<16,3> 	int16_3;

enum TOF_MODE {
	MODE_RAW = 0,
	MODE_AMP,
	MODE_PHASE,
	MODE_NUM
};

void getPhaseMap2(unsigned int regCtrl, int threshold, volatile uint16* dcs_in, volatile uint16* port0, volatile uint16* port1);

#endif

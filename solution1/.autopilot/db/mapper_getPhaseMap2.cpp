#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void getPhaseMap2(int*, int*, int, volatile void *, int, int);
extern "C" void apatb_getPhaseMap2_hw(int __xlx_apatb_param_regCtrl, volatile void * __xlx_apatb_param_dcs_in, volatile void * __xlx_apatb_param_port0, volatile void * __xlx_apatb_param_port1) {
  // Collect __xlx_port0__tmp_vec
  vector<sc_bv<32> >__xlx_port0__tmp_vec;
  for (int j = 0, e = 768000; j != e; ++j) {
    __xlx_port0__tmp_vec.push_back(((int*)__xlx_apatb_param_port0)[j]);
  }
  int __xlx_size_param_port0 = 768000;
  int __xlx_offset_param_port0 = 0;
  int __xlx_offset_byte_param_port0 = 0*4;
  int* __xlx_port0__input_buffer= new int[__xlx_port0__tmp_vec.size()];
  for (int i = 0; i < __xlx_port0__tmp_vec.size(); ++i) {
    __xlx_port0__input_buffer[i] = __xlx_port0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_port1__tmp_vec
  vector<sc_bv<32> >__xlx_port1__tmp_vec;
  for (int j = 0, e = 768000; j != e; ++j) {
    __xlx_port1__tmp_vec.push_back(((int*)__xlx_apatb_param_port1)[j]);
  }
  int __xlx_size_param_port1 = 768000;
  int __xlx_offset_param_port1 = 0;
  int __xlx_offset_byte_param_port1 = 0*4;
  int* __xlx_port1__input_buffer= new int[__xlx_port1__tmp_vec.size()];
  for (int i = 0; i < __xlx_port1__tmp_vec.size(); ++i) {
    __xlx_port1__input_buffer[i] = __xlx_port1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  getPhaseMap2(__xlx_port0__input_buffer, __xlx_port1__input_buffer, __xlx_apatb_param_regCtrl, __xlx_apatb_param_dcs_in, __xlx_offset_byte_param_port0, __xlx_offset_byte_param_port1);
// print __xlx_apatb_param_port0
  sc_bv<32>*__xlx_port0_output_buffer = new sc_bv<32>[__xlx_size_param_port0];
  for (int i = 0; i < __xlx_size_param_port0; ++i) {
    __xlx_port0_output_buffer[i] = __xlx_port0__input_buffer[i+__xlx_offset_param_port0];
  }
  for (int i = 0; i < __xlx_size_param_port0; ++i) {
    ((int*)__xlx_apatb_param_port0)[i] = __xlx_port0_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_port1
  sc_bv<32>*__xlx_port1_output_buffer = new sc_bv<32>[__xlx_size_param_port1];
  for (int i = 0; i < __xlx_size_param_port1; ++i) {
    __xlx_port1_output_buffer[i] = __xlx_port1__input_buffer[i+__xlx_offset_param_port1];
  }
  for (int i = 0; i < __xlx_size_param_port1; ++i) {
    ((int*)__xlx_apatb_param_port1)[i] = __xlx_port1_output_buffer[i].to_uint64();
  }
}

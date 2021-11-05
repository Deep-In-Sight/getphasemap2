#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_port0 "../tv/cdatafile/c.getPhaseMap2.autotvin_port0.dat"
#define AUTOTB_TVOUT_port0 "../tv/cdatafile/c.getPhaseMap2.autotvout_port0.dat"
// wrapc file define:
#define AUTOTB_TVIN_port1 "../tv/cdatafile/c.getPhaseMap2.autotvin_port1.dat"
#define AUTOTB_TVOUT_port1 "../tv/cdatafile/c.getPhaseMap2.autotvout_port1.dat"
// wrapc file define:
#define AUTOTB_TVIN_regCtrl "../tv/cdatafile/c.getPhaseMap2.autotvin_regCtrl.dat"
#define AUTOTB_TVOUT_regCtrl "../tv/cdatafile/c.getPhaseMap2.autotvout_regCtrl.dat"
// wrapc file define:
#define AUTOTB_TVIN_dcs_in "../tv/cdatafile/c.getPhaseMap2.autotvin_dcs_in.dat"
#define AUTOTB_TVOUT_dcs_in "../tv/cdatafile/c.getPhaseMap2.autotvout_dcs_in.dat"
// wrapc file define:
#define AUTOTB_TVIN_port0_offset "../tv/cdatafile/c.getPhaseMap2.autotvin_port0_offset.dat"
#define AUTOTB_TVOUT_port0_offset "../tv/cdatafile/c.getPhaseMap2.autotvout_port0_offset.dat"
// wrapc file define:
#define AUTOTB_TVIN_port1_offset "../tv/cdatafile/c.getPhaseMap2.autotvin_port1_offset.dat"
#define AUTOTB_TVOUT_port1_offset "../tv/cdatafile/c.getPhaseMap2.autotvout_port1_offset.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_port0 "../tv/rtldatafile/rtl.getPhaseMap2.autotvout_port0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_port1 "../tv/rtldatafile/rtl.getPhaseMap2.autotvout_port1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_regCtrl "../tv/rtldatafile/rtl.getPhaseMap2.autotvout_regCtrl.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_dcs_in "../tv/rtldatafile/rtl.getPhaseMap2.autotvout_dcs_in.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_port0_offset "../tv/rtldatafile/rtl.getPhaseMap2.autotvout_port0_offset.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_port1_offset "../tv/rtldatafile/rtl.getPhaseMap2.autotvout_port1_offset.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  port0_depth = 0;
  port1_depth = 0;
  regCtrl_depth = 0;
  dcs_in_depth = 0;
  port0_offset_depth = 0;
  port1_offset_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{port0 " << port0_depth << "}\n";
  total_list << "{port1 " << port1_depth << "}\n";
  total_list << "{regCtrl " << regCtrl_depth << "}\n";
  total_list << "{dcs_in " << dcs_in_depth << "}\n";
  total_list << "{port0_offset " << port0_offset_depth << "}\n";
  total_list << "{port1_offset " << port1_offset_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int port0_depth;
    int port1_depth;
    int regCtrl_depth;
    int dcs_in_depth;
    int port0_offset_depth;
    int port1_offset_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
extern "C" void getPhaseMap2_hw_stub_wrapper(int, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_getPhaseMap2_hw(int __xlx_apatb_param_regCtrl, volatile void * __xlx_apatb_param_dcs_in, volatile void * __xlx_apatb_param_port0, volatile void * __xlx_apatb_param_port1) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_port1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > port1_pc_buffer(768000);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "port1");
  
            // push token into output port buffer
            if (AESL_token != "") {
              port1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 768000; j < e; j += 1, ++i) {
            ((int*)__xlx_apatb_param_port1)[j] = port1_pc_buffer[i].to_int64();
          }}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dcs_in);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > dcs_in_pc_buffer(1228800);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dcs_in");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dcs_in_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1228800; j < e; j += 1, ++i) {
            ((short*)__xlx_apatb_param_dcs_in)[j] = dcs_in_pc_buffer[i].to_int64();
          }}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//port0
aesl_fh.touch(AUTOTB_TVIN_port0);
aesl_fh.touch(AUTOTB_TVOUT_port0);
//port1
aesl_fh.touch(AUTOTB_TVIN_port1);
aesl_fh.touch(AUTOTB_TVOUT_port1);
//regCtrl
aesl_fh.touch(AUTOTB_TVIN_regCtrl);
aesl_fh.touch(AUTOTB_TVOUT_regCtrl);
//dcs_in
aesl_fh.touch(AUTOTB_TVIN_dcs_in);
aesl_fh.touch(AUTOTB_TVOUT_dcs_in);
//port0_offset
aesl_fh.touch(AUTOTB_TVIN_port0_offset);
aesl_fh.touch(AUTOTB_TVOUT_port0_offset);
//port1_offset
aesl_fh.touch(AUTOTB_TVIN_port1_offset);
aesl_fh.touch(AUTOTB_TVOUT_port1_offset);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_port0 = 0;
// print port0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_port0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_port0 = 0*4;
  if (__xlx_apatb_param_port0) {
    for (int j = 0  - 0, e = 768000 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_port0)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_port0, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(768000, &tcl_file.port0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_port0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_port1 = 0;
// print port1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_port1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_port1 = 0*4;
  if (__xlx_apatb_param_port1) {
    for (int j = 0  - 0, e = 768000 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_port1)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_port1, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(768000, &tcl_file.port1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_port1, __xlx_sprintf_buffer.data());
}
// print regCtrl Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_regCtrl, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_regCtrl);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_regCtrl, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.regCtrl_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_regCtrl, __xlx_sprintf_buffer.data());
}
// print dcs_in Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_dcs_in, __xlx_sprintf_buffer.data());
    if (__xlx_apatb_param_dcs_in) {
    for (int j = 0  - 0, e = 1228800 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_dcs_in)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_dcs_in, __xlx_sprintf_buffer.data()); 
      }
  }

  tcl_file.set_num(1228800, &tcl_file.dcs_in_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_dcs_in, __xlx_sprintf_buffer.data());
}
// print port0_offset Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_port0_offset, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = __xlx_offset_byte_param_port0;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_port0_offset, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.port0_offset_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_port0_offset, __xlx_sprintf_buffer.data());
}
// print port1_offset Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_port1_offset, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = __xlx_offset_byte_param_port1;

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_port1_offset, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.port1_offset_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_port1_offset, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
getPhaseMap2_hw_stub_wrapper(__xlx_apatb_param_regCtrl, __xlx_apatb_param_dcs_in, __xlx_apatb_param_port0, __xlx_apatb_param_port1);
CodeState = DUMP_OUTPUTS;
// print port1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_port1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_port1 = 0*4;
  if (__xlx_apatb_param_port1) {
    for (int j = 0  - 0, e = 768000 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_port1)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_port1, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(768000, &tcl_file.port1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_port1, __xlx_sprintf_buffer.data());
}
// print dcs_in Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dcs_in, __xlx_sprintf_buffer.data());
    if (__xlx_apatb_param_dcs_in) {
    for (int j = 0  - 0, e = 1228800 - 0; j != e; ++j) {
sc_bv<16> __xlx_tmp_lv = ((short*)__xlx_apatb_param_dcs_in)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_dcs_in, __xlx_sprintf_buffer.data()); 
      }
  }

  tcl_file.set_num(1228800, &tcl_file.dcs_in_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dcs_in, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}

set moduleName getPhaseMap2
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {getPhaseMap2}
set C_modelType { void 0 }
set C_modelArgList {
	{ port0 int 32 regular {axi_master 0}  }
	{ port1 int 32 regular {axi_master 2}  }
	{ regCtrl int 32 regular {axi_slave 0}  }
	{ dcs_in int 16 regular {axi_s 0 volatile  { dcs_in Data } }  }
	{ port0_offset int 32 regular {axi_slave 0}  }
	{ port1_offset int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "port0", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "port0","cData": "int","bit_use": { "low": 0,"up": 0},"offset": { "type": "dynamic","port_name": "port0_offset","bundle": "control"},"direction": "READONLY","cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "port1", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "port1","cData": "int","bit_use": { "low": 0,"up": 0},"offset": { "type": "dynamic","port_name": "port1_offset","bundle": "control"},"direction": "READWRITE","cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "regCtrl", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "regCtrl","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "dcs_in", "interface" : "axis", "bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "dcs_in","cData": "short","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "port0_offset", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "port1_offset", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":32}, "offset_end" : {"in":39}} ]}
# RTL Port declarations: 
set portNum 113
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ m_axi_port0_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_port0_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_port0_AWADDR sc_out sc_lv 32 signal 0 } 
	{ m_axi_port0_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_port0_AWLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_port0_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_port0_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_port0_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_port0_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_port0_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_port0_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_port0_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_port0_WDATA sc_out sc_lv 32 signal 0 } 
	{ m_axi_port0_WSTRB sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_port0_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_port0_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_port0_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_port0_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_port0_ARADDR sc_out sc_lv 32 signal 0 } 
	{ m_axi_port0_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_port0_ARLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_port0_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_port0_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_port0_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_port0_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_port0_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_port0_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_port0_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_port0_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_port0_RDATA sc_in sc_lv 32 signal 0 } 
	{ m_axi_port0_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_port0_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_port0_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_port0_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_port0_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_port0_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_port0_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_port0_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_port0_BUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_port1_AWVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_port1_AWREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_port1_AWADDR sc_out sc_lv 32 signal 1 } 
	{ m_axi_port1_AWID sc_out sc_lv 1 signal 1 } 
	{ m_axi_port1_AWLEN sc_out sc_lv 8 signal 1 } 
	{ m_axi_port1_AWSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_port1_AWBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_port1_AWLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_port1_AWCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_AWPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_port1_AWQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_AWREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_AWUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_port1_WVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_port1_WREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_port1_WDATA sc_out sc_lv 32 signal 1 } 
	{ m_axi_port1_WSTRB sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_WLAST sc_out sc_logic 1 signal 1 } 
	{ m_axi_port1_WID sc_out sc_lv 1 signal 1 } 
	{ m_axi_port1_WUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_port1_ARVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_port1_ARREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_port1_ARADDR sc_out sc_lv 32 signal 1 } 
	{ m_axi_port1_ARID sc_out sc_lv 1 signal 1 } 
	{ m_axi_port1_ARLEN sc_out sc_lv 8 signal 1 } 
	{ m_axi_port1_ARSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_port1_ARBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_port1_ARLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_port1_ARCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_ARPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_port1_ARQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_ARREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_port1_ARUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_port1_RVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_port1_RREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_port1_RDATA sc_in sc_lv 32 signal 1 } 
	{ m_axi_port1_RLAST sc_in sc_logic 1 signal 1 } 
	{ m_axi_port1_RID sc_in sc_lv 1 signal 1 } 
	{ m_axi_port1_RUSER sc_in sc_lv 1 signal 1 } 
	{ m_axi_port1_RRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_port1_BVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_port1_BREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_port1_BRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_port1_BID sc_in sc_lv 1 signal 1 } 
	{ m_axi_port1_BUSER sc_in sc_lv 1 signal 1 } 
	{ dcs_in_TDATA sc_in sc_lv 16 signal 3 } 
	{ dcs_in_TVALID sc_in sc_logic 1 invld 3 } 
	{ dcs_in_TREADY sc_out sc_logic 1 inacc 3 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"getPhaseMap2","role":"start","value":"0","valid_bit":"0"},{"name":"getPhaseMap2","role":"continue","value":"0","valid_bit":"4"},{"name":"getPhaseMap2","role":"auto_start","value":"0","valid_bit":"7"},{"name":"regCtrl","role":"data","value":"16"},{"name":"port0_offset","role":"data","value":"24"},{"name":"port1_offset","role":"data","value":"32"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"getPhaseMap2","role":"start","value":"0","valid_bit":"0"},{"name":"getPhaseMap2","role":"done","value":"0","valid_bit":"1"},{"name":"getPhaseMap2","role":"idle","value":"0","valid_bit":"2"},{"name":"getPhaseMap2","role":"ready","value":"0","valid_bit":"3"},{"name":"getPhaseMap2","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "m_axi_port0_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "AWVALID" }} , 
 	{ "name": "m_axi_port0_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "AWREADY" }} , 
 	{ "name": "m_axi_port0_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port0", "role": "AWADDR" }} , 
 	{ "name": "m_axi_port0_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "AWID" }} , 
 	{ "name": "m_axi_port0_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "port0", "role": "AWLEN" }} , 
 	{ "name": "m_axi_port0_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port0", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_port0_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port0", "role": "AWBURST" }} , 
 	{ "name": "m_axi_port0_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port0", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_port0_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_port0_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port0", "role": "AWPROT" }} , 
 	{ "name": "m_axi_port0_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "AWQOS" }} , 
 	{ "name": "m_axi_port0_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "AWREGION" }} , 
 	{ "name": "m_axi_port0_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "AWUSER" }} , 
 	{ "name": "m_axi_port0_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "WVALID" }} , 
 	{ "name": "m_axi_port0_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "WREADY" }} , 
 	{ "name": "m_axi_port0_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port0", "role": "WDATA" }} , 
 	{ "name": "m_axi_port0_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "WSTRB" }} , 
 	{ "name": "m_axi_port0_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "WLAST" }} , 
 	{ "name": "m_axi_port0_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "WID" }} , 
 	{ "name": "m_axi_port0_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "WUSER" }} , 
 	{ "name": "m_axi_port0_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "ARVALID" }} , 
 	{ "name": "m_axi_port0_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "ARREADY" }} , 
 	{ "name": "m_axi_port0_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port0", "role": "ARADDR" }} , 
 	{ "name": "m_axi_port0_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "ARID" }} , 
 	{ "name": "m_axi_port0_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "port0", "role": "ARLEN" }} , 
 	{ "name": "m_axi_port0_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port0", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_port0_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port0", "role": "ARBURST" }} , 
 	{ "name": "m_axi_port0_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port0", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_port0_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_port0_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port0", "role": "ARPROT" }} , 
 	{ "name": "m_axi_port0_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "ARQOS" }} , 
 	{ "name": "m_axi_port0_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port0", "role": "ARREGION" }} , 
 	{ "name": "m_axi_port0_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "ARUSER" }} , 
 	{ "name": "m_axi_port0_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "RVALID" }} , 
 	{ "name": "m_axi_port0_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "RREADY" }} , 
 	{ "name": "m_axi_port0_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port0", "role": "RDATA" }} , 
 	{ "name": "m_axi_port0_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "RLAST" }} , 
 	{ "name": "m_axi_port0_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "RID" }} , 
 	{ "name": "m_axi_port0_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "RUSER" }} , 
 	{ "name": "m_axi_port0_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port0", "role": "RRESP" }} , 
 	{ "name": "m_axi_port0_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "BVALID" }} , 
 	{ "name": "m_axi_port0_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "BREADY" }} , 
 	{ "name": "m_axi_port0_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port0", "role": "BRESP" }} , 
 	{ "name": "m_axi_port0_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "BID" }} , 
 	{ "name": "m_axi_port0_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port0", "role": "BUSER" }} , 
 	{ "name": "m_axi_port1_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "AWVALID" }} , 
 	{ "name": "m_axi_port1_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "AWREADY" }} , 
 	{ "name": "m_axi_port1_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port1", "role": "AWADDR" }} , 
 	{ "name": "m_axi_port1_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "AWID" }} , 
 	{ "name": "m_axi_port1_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "port1", "role": "AWLEN" }} , 
 	{ "name": "m_axi_port1_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port1", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_port1_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port1", "role": "AWBURST" }} , 
 	{ "name": "m_axi_port1_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port1", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_port1_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_port1_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port1", "role": "AWPROT" }} , 
 	{ "name": "m_axi_port1_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "AWQOS" }} , 
 	{ "name": "m_axi_port1_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "AWREGION" }} , 
 	{ "name": "m_axi_port1_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "AWUSER" }} , 
 	{ "name": "m_axi_port1_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "WVALID" }} , 
 	{ "name": "m_axi_port1_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "WREADY" }} , 
 	{ "name": "m_axi_port1_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port1", "role": "WDATA" }} , 
 	{ "name": "m_axi_port1_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "WSTRB" }} , 
 	{ "name": "m_axi_port1_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "WLAST" }} , 
 	{ "name": "m_axi_port1_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "WID" }} , 
 	{ "name": "m_axi_port1_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "WUSER" }} , 
 	{ "name": "m_axi_port1_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "ARVALID" }} , 
 	{ "name": "m_axi_port1_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "ARREADY" }} , 
 	{ "name": "m_axi_port1_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port1", "role": "ARADDR" }} , 
 	{ "name": "m_axi_port1_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "ARID" }} , 
 	{ "name": "m_axi_port1_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "port1", "role": "ARLEN" }} , 
 	{ "name": "m_axi_port1_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port1", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_port1_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port1", "role": "ARBURST" }} , 
 	{ "name": "m_axi_port1_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port1", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_port1_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_port1_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "port1", "role": "ARPROT" }} , 
 	{ "name": "m_axi_port1_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "ARQOS" }} , 
 	{ "name": "m_axi_port1_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "port1", "role": "ARREGION" }} , 
 	{ "name": "m_axi_port1_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "ARUSER" }} , 
 	{ "name": "m_axi_port1_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "RVALID" }} , 
 	{ "name": "m_axi_port1_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "RREADY" }} , 
 	{ "name": "m_axi_port1_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "port1", "role": "RDATA" }} , 
 	{ "name": "m_axi_port1_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "RLAST" }} , 
 	{ "name": "m_axi_port1_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "RID" }} , 
 	{ "name": "m_axi_port1_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "RUSER" }} , 
 	{ "name": "m_axi_port1_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port1", "role": "RRESP" }} , 
 	{ "name": "m_axi_port1_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "BVALID" }} , 
 	{ "name": "m_axi_port1_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "BREADY" }} , 
 	{ "name": "m_axi_port1_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "port1", "role": "BRESP" }} , 
 	{ "name": "m_axi_port1_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "BID" }} , 
 	{ "name": "m_axi_port1_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "port1", "role": "BUSER" }} , 
 	{ "name": "dcs_in_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "dcs_in", "role": "TDATA" }} , 
 	{ "name": "dcs_in_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "dcs_in", "role": "TVALID" }} , 
 	{ "name": "dcs_in_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "dcs_in", "role": "TREADY" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"],
		"CDFG" : "getPhaseMap2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1228863", "EstimateLatencyMax" : "1382529",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "port0", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "port0_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "port0_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "port1", "Type" : "MAXI", "Direction" : "IO",
				"BlockSignal" : [
					{"Name" : "port1_blk_n_AW", "Type" : "RtlSignal"},
					{"Name" : "port1_blk_n_W", "Type" : "RtlSignal"},
					{"Name" : "port1_blk_n_B", "Type" : "RtlSignal"},
					{"Name" : "port1_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "port1_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "regCtrl", "Type" : "None", "Direction" : "I"},
			{"Name" : "dcs_in", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "dcs_in_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "port0_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "port1_offset", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.control_s_axi_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.port0_m_axi_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.port1_m_axi_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_generic_atan2_16_3_s_fu_660", "Parent" : "0",
		"CDFG" : "generic_atan2_16_3_s",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0", "real_start" : "0",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "15", "EstimateLatencyMin" : "15", "EstimateLatencyMax" : "15",
		"Combinational" : "0",
		"Datapath" : "1",
		"ClockEnable" : "1",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in1", "Type" : "None", "Direction" : "I"},
			{"Name" : "in2", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_sqrt_fixed_32_32_s_fu_666", "Parent" : "0",
		"CDFG" : "sqrt_fixed_32_32_s",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "0", "ap_start" : "0", "ap_ready" : "0", "ap_done" : "0", "ap_continue" : "0", "ap_idle" : "0", "real_start" : "0",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "8", "EstimateLatencyMin" : "8", "EstimateLatencyMax" : "8",
		"Combinational" : "0",
		"Datapath" : "1",
		"ClockEnable" : "1",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "x", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_48ns_50ns_80_5_1_U4", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.udiv_48s_16ns_16_52_1_U5", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.udiv_48s_16ns_8_52_1_U6", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_mul_16s_16s_32_4_1_U7", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mac_muladd_13s_13s_32s_32_4_1_U8", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.regslice_both_dcs_in_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	getPhaseMap2 {
		port0 {Type I LastRead 46 FirstWrite -1}
		port1 {Type IO LastRead 96 FirstWrite 4}
		regCtrl {Type I LastRead 0 FirstWrite -1}
		dcs_in {Type I LastRead 32 FirstWrite -1}
		port0_offset {Type I LastRead 0 FirstWrite -1}
		port1_offset {Type I LastRead 0 FirstWrite -1}}
	generic_atan2_16_3_s {
		in1 {Type I LastRead 0 FirstWrite -1}
		in2 {Type I LastRead 0 FirstWrite -1}}
	sqrt_fixed_32_32_s {
		x {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "1228863", "Max" : "1382529"}
	, {"Name" : "Interval", "Min" : "1228864", "Max" : "1382530"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
]}

set Spec2ImplPortList { 
	port0 { m_axi {  { m_axi_port0_AWVALID VALID 1 1 }  { m_axi_port0_AWREADY READY 0 1 }  { m_axi_port0_AWADDR ADDR 1 32 }  { m_axi_port0_AWID ID 1 1 }  { m_axi_port0_AWLEN LEN 1 8 }  { m_axi_port0_AWSIZE SIZE 1 3 }  { m_axi_port0_AWBURST BURST 1 2 }  { m_axi_port0_AWLOCK LOCK 1 2 }  { m_axi_port0_AWCACHE CACHE 1 4 }  { m_axi_port0_AWPROT PROT 1 3 }  { m_axi_port0_AWQOS QOS 1 4 }  { m_axi_port0_AWREGION REGION 1 4 }  { m_axi_port0_AWUSER USER 1 1 }  { m_axi_port0_WVALID VALID 1 1 }  { m_axi_port0_WREADY READY 0 1 }  { m_axi_port0_WDATA DATA 1 32 }  { m_axi_port0_WSTRB STRB 1 4 }  { m_axi_port0_WLAST LAST 1 1 }  { m_axi_port0_WID ID 1 1 }  { m_axi_port0_WUSER USER 1 1 }  { m_axi_port0_ARVALID VALID 1 1 }  { m_axi_port0_ARREADY READY 0 1 }  { m_axi_port0_ARADDR ADDR 1 32 }  { m_axi_port0_ARID ID 1 1 }  { m_axi_port0_ARLEN LEN 1 8 }  { m_axi_port0_ARSIZE SIZE 1 3 }  { m_axi_port0_ARBURST BURST 1 2 }  { m_axi_port0_ARLOCK LOCK 1 2 }  { m_axi_port0_ARCACHE CACHE 1 4 }  { m_axi_port0_ARPROT PROT 1 3 }  { m_axi_port0_ARQOS QOS 1 4 }  { m_axi_port0_ARREGION REGION 1 4 }  { m_axi_port0_ARUSER USER 1 1 }  { m_axi_port0_RVALID VALID 0 1 }  { m_axi_port0_RREADY READY 1 1 }  { m_axi_port0_RDATA DATA 0 32 }  { m_axi_port0_RLAST LAST 0 1 }  { m_axi_port0_RID ID 0 1 }  { m_axi_port0_RUSER USER 0 1 }  { m_axi_port0_RRESP RESP 0 2 }  { m_axi_port0_BVALID VALID 0 1 }  { m_axi_port0_BREADY READY 1 1 }  { m_axi_port0_BRESP RESP 0 2 }  { m_axi_port0_BID ID 0 1 }  { m_axi_port0_BUSER USER 0 1 } } }
	port1 { m_axi {  { m_axi_port1_AWVALID VALID 1 1 }  { m_axi_port1_AWREADY READY 0 1 }  { m_axi_port1_AWADDR ADDR 1 32 }  { m_axi_port1_AWID ID 1 1 }  { m_axi_port1_AWLEN LEN 1 8 }  { m_axi_port1_AWSIZE SIZE 1 3 }  { m_axi_port1_AWBURST BURST 1 2 }  { m_axi_port1_AWLOCK LOCK 1 2 }  { m_axi_port1_AWCACHE CACHE 1 4 }  { m_axi_port1_AWPROT PROT 1 3 }  { m_axi_port1_AWQOS QOS 1 4 }  { m_axi_port1_AWREGION REGION 1 4 }  { m_axi_port1_AWUSER USER 1 1 }  { m_axi_port1_WVALID VALID 1 1 }  { m_axi_port1_WREADY READY 0 1 }  { m_axi_port1_WDATA DATA 1 32 }  { m_axi_port1_WSTRB STRB 1 4 }  { m_axi_port1_WLAST LAST 1 1 }  { m_axi_port1_WID ID 1 1 }  { m_axi_port1_WUSER USER 1 1 }  { m_axi_port1_ARVALID VALID 1 1 }  { m_axi_port1_ARREADY READY 0 1 }  { m_axi_port1_ARADDR ADDR 1 32 }  { m_axi_port1_ARID ID 1 1 }  { m_axi_port1_ARLEN LEN 1 8 }  { m_axi_port1_ARSIZE SIZE 1 3 }  { m_axi_port1_ARBURST BURST 1 2 }  { m_axi_port1_ARLOCK LOCK 1 2 }  { m_axi_port1_ARCACHE CACHE 1 4 }  { m_axi_port1_ARPROT PROT 1 3 }  { m_axi_port1_ARQOS QOS 1 4 }  { m_axi_port1_ARREGION REGION 1 4 }  { m_axi_port1_ARUSER USER 1 1 }  { m_axi_port1_RVALID VALID 0 1 }  { m_axi_port1_RREADY READY 1 1 }  { m_axi_port1_RDATA DATA 0 32 }  { m_axi_port1_RLAST LAST 0 1 }  { m_axi_port1_RID ID 0 1 }  { m_axi_port1_RUSER USER 0 1 }  { m_axi_port1_RRESP RESP 0 2 }  { m_axi_port1_BVALID VALID 0 1 }  { m_axi_port1_BREADY READY 1 1 }  { m_axi_port1_BRESP RESP 0 2 }  { m_axi_port1_BID ID 0 1 }  { m_axi_port1_BUSER USER 0 1 } } }
	dcs_in { axis {  { dcs_in_TDATA in_data 0 16 }  { dcs_in_TVALID in_vld 0 1 }  { dcs_in_TREADY in_acc 1 1 } } }
}

set busDeadlockParameterList { 
	{ port0 { NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 32 MAX_WRITE_BURST_LENGTH 32 } } \
	{ port1 { NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 32 MAX_WRITE_BURST_LENGTH 32 } } \
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
	{ port0 1 }
	{ port1 1 }
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
	{ port0 1 }
	{ port1 1 }
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}

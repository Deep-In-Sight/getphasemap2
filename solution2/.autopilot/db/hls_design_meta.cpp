#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("m_axi_port0_AWVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_port0_AWREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_port0_AWADDR", 32, hls_out, 0, "m_axi", "ADDR", 1),
	Port_Property("m_axi_port0_AWID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_port0_AWLEN", 8, hls_out, 0, "m_axi", "LEN", 1),
	Port_Property("m_axi_port0_AWSIZE", 3, hls_out, 0, "m_axi", "SIZE", 1),
	Port_Property("m_axi_port0_AWBURST", 2, hls_out, 0, "m_axi", "BURST", 1),
	Port_Property("m_axi_port0_AWLOCK", 2, hls_out, 0, "m_axi", "LOCK", 1),
	Port_Property("m_axi_port0_AWCACHE", 4, hls_out, 0, "m_axi", "CACHE", 1),
	Port_Property("m_axi_port0_AWPROT", 3, hls_out, 0, "m_axi", "PROT", 1),
	Port_Property("m_axi_port0_AWQOS", 4, hls_out, 0, "m_axi", "QOS", 1),
	Port_Property("m_axi_port0_AWREGION", 4, hls_out, 0, "m_axi", "REGION", 1),
	Port_Property("m_axi_port0_AWUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_port0_WVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_port0_WREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_port0_WDATA", 32, hls_out, 0, "m_axi", "DATA", 1),
	Port_Property("m_axi_port0_WSTRB", 4, hls_out, 0, "m_axi", "STRB", 1),
	Port_Property("m_axi_port0_WLAST", 1, hls_out, 0, "m_axi", "LAST", 1),
	Port_Property("m_axi_port0_WID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_port0_WUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_port0_ARVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_port0_ARREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_port0_ARADDR", 32, hls_out, 0, "m_axi", "ADDR", 1),
	Port_Property("m_axi_port0_ARID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_port0_ARLEN", 8, hls_out, 0, "m_axi", "LEN", 1),
	Port_Property("m_axi_port0_ARSIZE", 3, hls_out, 0, "m_axi", "SIZE", 1),
	Port_Property("m_axi_port0_ARBURST", 2, hls_out, 0, "m_axi", "BURST", 1),
	Port_Property("m_axi_port0_ARLOCK", 2, hls_out, 0, "m_axi", "LOCK", 1),
	Port_Property("m_axi_port0_ARCACHE", 4, hls_out, 0, "m_axi", "CACHE", 1),
	Port_Property("m_axi_port0_ARPROT", 3, hls_out, 0, "m_axi", "PROT", 1),
	Port_Property("m_axi_port0_ARQOS", 4, hls_out, 0, "m_axi", "QOS", 1),
	Port_Property("m_axi_port0_ARREGION", 4, hls_out, 0, "m_axi", "REGION", 1),
	Port_Property("m_axi_port0_ARUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_port0_RVALID", 1, hls_in, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_port0_RREADY", 1, hls_out, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_port0_RDATA", 32, hls_in, 0, "m_axi", "DATA", 1),
	Port_Property("m_axi_port0_RLAST", 1, hls_in, 0, "m_axi", "LAST", 1),
	Port_Property("m_axi_port0_RID", 1, hls_in, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_port0_RUSER", 1, hls_in, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_port0_RRESP", 2, hls_in, 0, "m_axi", "RESP", 1),
	Port_Property("m_axi_port0_BVALID", 1, hls_in, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_port0_BREADY", 1, hls_out, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_port0_BRESP", 2, hls_in, 0, "m_axi", "RESP", 1),
	Port_Property("m_axi_port0_BID", 1, hls_in, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_port0_BUSER", 1, hls_in, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_port1_AWVALID", 1, hls_out, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_port1_AWREADY", 1, hls_in, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_port1_AWADDR", 32, hls_out, 1, "m_axi", "ADDR", 1),
	Port_Property("m_axi_port1_AWID", 1, hls_out, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_port1_AWLEN", 8, hls_out, 1, "m_axi", "LEN", 1),
	Port_Property("m_axi_port1_AWSIZE", 3, hls_out, 1, "m_axi", "SIZE", 1),
	Port_Property("m_axi_port1_AWBURST", 2, hls_out, 1, "m_axi", "BURST", 1),
	Port_Property("m_axi_port1_AWLOCK", 2, hls_out, 1, "m_axi", "LOCK", 1),
	Port_Property("m_axi_port1_AWCACHE", 4, hls_out, 1, "m_axi", "CACHE", 1),
	Port_Property("m_axi_port1_AWPROT", 3, hls_out, 1, "m_axi", "PROT", 1),
	Port_Property("m_axi_port1_AWQOS", 4, hls_out, 1, "m_axi", "QOS", 1),
	Port_Property("m_axi_port1_AWREGION", 4, hls_out, 1, "m_axi", "REGION", 1),
	Port_Property("m_axi_port1_AWUSER", 1, hls_out, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_port1_WVALID", 1, hls_out, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_port1_WREADY", 1, hls_in, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_port1_WDATA", 32, hls_out, 1, "m_axi", "DATA", 1),
	Port_Property("m_axi_port1_WSTRB", 4, hls_out, 1, "m_axi", "STRB", 1),
	Port_Property("m_axi_port1_WLAST", 1, hls_out, 1, "m_axi", "LAST", 1),
	Port_Property("m_axi_port1_WID", 1, hls_out, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_port1_WUSER", 1, hls_out, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_port1_ARVALID", 1, hls_out, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_port1_ARREADY", 1, hls_in, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_port1_ARADDR", 32, hls_out, 1, "m_axi", "ADDR", 1),
	Port_Property("m_axi_port1_ARID", 1, hls_out, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_port1_ARLEN", 8, hls_out, 1, "m_axi", "LEN", 1),
	Port_Property("m_axi_port1_ARSIZE", 3, hls_out, 1, "m_axi", "SIZE", 1),
	Port_Property("m_axi_port1_ARBURST", 2, hls_out, 1, "m_axi", "BURST", 1),
	Port_Property("m_axi_port1_ARLOCK", 2, hls_out, 1, "m_axi", "LOCK", 1),
	Port_Property("m_axi_port1_ARCACHE", 4, hls_out, 1, "m_axi", "CACHE", 1),
	Port_Property("m_axi_port1_ARPROT", 3, hls_out, 1, "m_axi", "PROT", 1),
	Port_Property("m_axi_port1_ARQOS", 4, hls_out, 1, "m_axi", "QOS", 1),
	Port_Property("m_axi_port1_ARREGION", 4, hls_out, 1, "m_axi", "REGION", 1),
	Port_Property("m_axi_port1_ARUSER", 1, hls_out, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_port1_RVALID", 1, hls_in, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_port1_RREADY", 1, hls_out, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_port1_RDATA", 32, hls_in, 1, "m_axi", "DATA", 1),
	Port_Property("m_axi_port1_RLAST", 1, hls_in, 1, "m_axi", "LAST", 1),
	Port_Property("m_axi_port1_RID", 1, hls_in, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_port1_RUSER", 1, hls_in, 1, "m_axi", "USER", 1),
	Port_Property("m_axi_port1_RRESP", 2, hls_in, 1, "m_axi", "RESP", 1),
	Port_Property("m_axi_port1_BVALID", 1, hls_in, 1, "m_axi", "VALID", 1),
	Port_Property("m_axi_port1_BREADY", 1, hls_out, 1, "m_axi", "READY", 1),
	Port_Property("m_axi_port1_BRESP", 2, hls_in, 1, "m_axi", "RESP", 1),
	Port_Property("m_axi_port1_BID", 1, hls_in, 1, "m_axi", "ID", 1),
	Port_Property("m_axi_port1_BUSER", 1, hls_in, 1, "m_axi", "USER", 1),
	Port_Property("dcs_in_TDATA", 16, hls_in, 3, "axis", "in_data", 1),
	Port_Property("dcs_in_TVALID", 1, hls_in, 3, "axis", "in_vld", 1),
	Port_Property("dcs_in_TREADY", 1, hls_out, 3, "axis", "in_acc", 1),
	Port_Property("s_axi_control_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_AWADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_ARADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "getPhaseMap2";
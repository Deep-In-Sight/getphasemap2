############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project getPhaseMap2
set_top getPhaseMap2
add_files getPhaseMap2/getPhaseMap.h
add_files getPhaseMap2/getPhaseMap.cpp
add_files -tb getPhaseMap2/test_getPhaseMap.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xczu3eg-sbva484-1-i}
create_clock -period 10 -name default
config_interface -m_axi_addr64=0 -m_axi_alignment_byte_size 4 -m_axi_conservative_mode -register_io scalar_in
config_export -description {ToF Sensor DCS to Phase calculation} -display_name getPhaseMap2 -format ip_catalog -output D:/workspace/vivado/ip_repo/getPhaseMap2.zip -rtl verilog -vendor DeepInsight.ai -version 2.0
source "./getPhaseMap2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -wave_debug -trace_level all
export_design -rtl verilog -format ip_catalog -description "ToF Sensor DCS to Phase calculation" -vendor "DeepInsight.ai" -version "2.0" -display_name "getPhaseMap2" -output D:/workspace/vivado/ip_repo/getPhaseMap2.zip

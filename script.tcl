set TARGET "../ip_repo/getPhaseMap2.zip"
set IP_DESC "ToF Sensor DCS to Phase calculation"
set IP_VERSION "2.0"
set IP_VENDOR "DeepInsight.ai"
set IP_NAME "getPhaseMap2"

open_project project
set_top getPhaseMap2
add_files ./project/src/getPhaseMap.cpp
add_files -tb ./project/src/test_getPhaseMap.cpp
open_solution "solution1" -flow_target vivado
set_part {xc7z020-clg400-1}
create_clock -period 8 -name default
config_interface -m_axi_addr64=0 -m_axi_alignment_byte_size 4 -m_axi_conservative_mode -register_io scalar_in
set_clock_uncertainty 1
# csim_design
csynth_design
export_design -rtl verilog -format ip_catalog -description $IP_DESC -vendor $IP_VENDOR -version $IP_VERSION -display_name $IP_NAME -output $TARGET


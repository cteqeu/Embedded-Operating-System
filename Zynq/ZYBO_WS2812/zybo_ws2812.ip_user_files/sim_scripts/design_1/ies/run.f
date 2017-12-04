-makelib ies/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_WS2812_0_0/sim/design_1_WS2812_0_0.vhd" \
  "../../../bd/design_1/hdl/design_1.vhd" \
-endlib
-makelib ies/axi_infrastructure_v1_1_0 \
  "../../../../zybo_ws2812.srcs/sources_1/bd/design_1/ipshared/7e3a/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib ies/xil_common_vip_v1_0_0 -sv \
  "../../../../zybo_ws2812.srcs/sources_1/bd/design_1/ipshared/2ad9/hdl/xil_common_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib ies/smartconnect_v1_0 -sv \
  "../../../../zybo_ws2812.srcs/sources_1/bd/design_1/ipshared/39ca/hdl/sc_util_v1_0_vl_rfs.sv" \
-endlib
-makelib ies/axi_protocol_checker_v1_1_14 -sv \
  "../../../../zybo_ws2812.srcs/sources_1/bd/design_1/ipshared/a1b2/hdl/axi_protocol_checker_v1_1_vl_rfs.sv" \
-endlib
-makelib ies/axi_vip_v1_0_2 -sv \
  "../../../../zybo_ws2812.srcs/sources_1/bd/design_1/ipshared/6eb1/hdl/axi_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib ies/axi_vip_v1_0_1 -sv \
  "../../../../zybo_ws2812.srcs/sources_1/bd/design_1/ipshared/1d61/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib ies/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
-endlib
-makelib ies/xil_defaultlib \
  glbl.v
-endlib


connect -url tcp:127.0.0.1:3121
source D:/FPGA/Olimex_RGB_Matrix/matrix_vc/sdk3/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -filter {jtag_cable_name =~ "Digilent Zybo 210279572606A" && level==0} -index 1
fpga -file D:/FPGA/Olimex_RGB_Matrix/matrix_vc/sdk3/design_1_wrapper_hw_platform_0/design_1_wrapper.bit
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279572606A"} -index 0
loadhw -hw D:/FPGA/Olimex_RGB_Matrix/matrix_vc/sdk3/design_1_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279572606A"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279572606A"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279572606A"} -index 0
dow D:/FPGA/Olimex_RGB_Matrix/matrix_vc/sdk3/test/Debug/test.elf
configparams force-mem-access 0
bpadd -addr &main

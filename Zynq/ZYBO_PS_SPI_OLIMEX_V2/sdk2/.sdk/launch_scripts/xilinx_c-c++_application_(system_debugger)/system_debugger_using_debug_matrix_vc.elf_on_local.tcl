connect -url tcp:127.0.0.1:3121
source D:/FPGA/hardware/Olimex_RGB_Matrix/matrix_vc/sdk2/design_1_wrapper_hw_platform_0/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279574222A"} -index 0
loadhw -hw D:/FPGA/hardware/Olimex_RGB_Matrix/matrix_vc/sdk2/design_1_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent Zybo 210279574222A"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279574222A"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent Zybo 210279574222A"} -index 0
dow D:/FPGA/hardware/Olimex_RGB_Matrix/matrix_vc/sdk2/Matrix_vc/Debug/Matrix_vc.elf
configparams force-mem-access 0
bpadd -addr &main

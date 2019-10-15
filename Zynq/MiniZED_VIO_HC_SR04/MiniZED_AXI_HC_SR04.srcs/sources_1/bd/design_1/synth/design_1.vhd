--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.1.3 (win64) Build 2644227 Wed Sep  4 09:45:24 MDT 2019
--Date        : Tue Oct 15 14:20:25 2019
--Host        : PF1K6K4W running 64-bit major release  (build 9200)
--Command     : generate_target design_1.bd
--Design      : design_1
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1 is
  port (
    sonar_echo_0 : in STD_LOGIC;
    sonar_trig_0 : out STD_LOGIC
  );
  attribute CORE_GENERATION_INFO : string;
  attribute CORE_GENERATION_INFO of design_1 : entity is "design_1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_1,x_ipVersion=1.00.a,x_ipLanguage=VHDL,numBlks=4,numReposBlks=4,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=0,numHdlrefBlks=2,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}";
  attribute HW_HANDOFF : string;
  attribute HW_HANDOFF of design_1 : entity is "design_1.hwdef";
end design_1;

architecture STRUCTURE of design_1 is
  component design_1_vhdlnoclk_0_0 is
  port (
    clk65MHz : out STD_LOGIC
  );
  end component design_1_vhdlnoclk_0_0;
  component design_1_clk_wiz_0_0 is
  port (
    clk_in1 : in STD_LOGIC;
    clk100MHz : out STD_LOGIC
  );
  end component design_1_clk_wiz_0_0;
  component design_1_HC_SR04_0_0 is
  port (
    clk : in STD_LOGIC;
    sonar_trig : out STD_LOGIC;
    sonar_echo : in STD_LOGIC;
    centimeter : out STD_LOGIC_VECTOR ( 15 downto 0 )
  );
  end component design_1_HC_SR04_0_0;
  component design_1_vio_0_0 is
  port (
    clk : in STD_LOGIC;
    probe_in0 : in STD_LOGIC_VECTOR ( 15 downto 0 )
  );
  end component design_1_vio_0_0;
  signal HC_SR04_0_centimeter : STD_LOGIC_VECTOR ( 15 downto 0 );
  signal HC_SR04_0_sonar_trig : STD_LOGIC;
  signal clk_wiz_0_clk100MHz : STD_LOGIC;
  signal sonar_echo_0_1 : STD_LOGIC;
  signal vhdlnoclk_0_clk65MHz : STD_LOGIC;
begin
  sonar_echo_0_1 <= sonar_echo_0;
  sonar_trig_0 <= HC_SR04_0_sonar_trig;
HC_SR04_0: component design_1_HC_SR04_0_0
     port map (
      centimeter(15 downto 0) => HC_SR04_0_centimeter(15 downto 0),
      clk => clk_wiz_0_clk100MHz,
      sonar_echo => sonar_echo_0_1,
      sonar_trig => HC_SR04_0_sonar_trig
    );
clk_wiz_0: component design_1_clk_wiz_0_0
     port map (
      clk100MHz => clk_wiz_0_clk100MHz,
      clk_in1 => vhdlnoclk_0_clk65MHz
    );
vhdlnoclk_0: component design_1_vhdlnoclk_0_0
     port map (
      clk65MHz => vhdlnoclk_0_clk65MHz
    );
vio_0: component design_1_vio_0_0
     port map (
      clk => clk_wiz_0_clk100MHz,
      probe_in0(15 downto 0) => HC_SR04_0_centimeter(15 downto 0)
    );
end STRUCTURE;

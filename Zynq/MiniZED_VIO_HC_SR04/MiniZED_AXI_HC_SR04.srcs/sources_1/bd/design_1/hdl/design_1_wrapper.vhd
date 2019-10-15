--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.1.3 (win64) Build 2644227 Wed Sep  4 09:45:24 MDT 2019
--Date        : Tue Oct 15 14:20:25 2019
--Host        : PF1K6K4W running 64-bit major release  (build 9200)
--Command     : generate_target design_1_wrapper.bd
--Design      : design_1_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_1_wrapper is
  port (
    sonar_echo_0 : in STD_LOGIC;
    sonar_trig_0 : out STD_LOGIC
  );
end design_1_wrapper;

architecture STRUCTURE of design_1_wrapper is
  component design_1 is
  port (
    sonar_echo_0 : in STD_LOGIC;
    sonar_trig_0 : out STD_LOGIC
  );
  end component design_1;
begin
design_1_i: component design_1
     port map (
      sonar_echo_0 => sonar_echo_0,
      sonar_trig_0 => sonar_trig_0
    );
end STRUCTURE;

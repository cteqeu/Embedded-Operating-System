----------------------------------------------------------------------------------
-- Company:     CTEQ.EU
-- Engineer:    Vincent Claes
-- 
-- Create Date: 24.09.2018 09:31:19
-- Design Name: 
-- Module Name: looplicht - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity blink is
  Port (
        CLK : in std_logic;
        LED : out std_logic_vector(3 downto 0)
  );
end blink;

architecture Behavioral of blink is
signal prscaler : signed (27 downto 0) := "0111011100110101100101000000";
signal prscaler_counter : signed (27 downto 0) :=(others=>'0');
signal HzClock  : std_logic := '0';

---- 125 MHz clock on Zybo Board
---- prscaler => 0111011100110101100101000000 = 125000000
begin

process(CLK)
begin

  if rising_edge(CLK) then
    prscaler_counter <= prscaler_counter + 1;
    if(prscaler_counter > prscaler) then
       HzClock <= not HzClock;
       prscaler_counter <= (others => '0');
    end if;
  end if;
end process;

LED(0) <=HzClock;
LED(1) <=HzClock;
LED(2) <= HzClock;
LED(3) <= HzClock;

end Behavioral;


--- XDC contents :
--- set_property PACKAGE_PIN M14 [get_ports {LED[3]}]
--- set_property PACKAGE_PIN M15 [get_ports {LED[2]}]
--- set_property PACKAGE_PIN G14 [get_ports {LED[1]}]
--- set_property PACKAGE_PIN D18 [get_ports {LED[0]}]
--- set_property IOSTANDARD LVCMOS33 [get_ports {LED[3]}]
--- set_property IOSTANDARD LVCMOS33 [get_ports {LED[2]}]
--- set_property IOSTANDARD LVCMOS33 [get_ports {LED[1]}]
--- set_property IOSTANDARD LVCMOS33 [get_ports {LED[0]}]
--- set_property PACKAGE_PIN L16 [get_ports CLK]
--- set_property IOSTANDARD LVCMOS33 [get_ports CLK]


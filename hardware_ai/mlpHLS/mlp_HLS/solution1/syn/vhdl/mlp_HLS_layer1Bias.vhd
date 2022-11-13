-- ==============================================================
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity mlp_HLS_layer1Bias_rom is 
    generic(
             DWIDTH     : integer := 32; 
             AWIDTH     : integer := 7; 
             MEM_SIZE    : integer := 112
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of mlp_HLS_layer1Bias_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "10111101001110110101011010011010", 
    1 => "10111100001111001011111100000011", 
    2 => "00000000000000000000000000000000", 
    3 => "00111100010111010110110010101000", 
    4 => "10111100101111111010110001101101", 
    5 => "10111100010010001110011101101111", 
    6 => "10111100011111100100111011100111", 
    7 => "00000000000000000000000000000000", 
    8 => "10111100001011100011010000100101", 
    9 => "00111100111001011001101011100001", 
    10 => "00111100100000001111001011101101", 
    11 => "10111100000010010011100000000011", 
    12 => "00000000000000000000000000000000", 
    13 => "10111100001100001010000101101010", 
    14 => "10111100101010000000101001010000", 
    15 to 16=> "00000000000000000000000000000000", 
    17 => "10111100111001110000111111010011", 
    18 => "00111100011011001100110001100110", 
    19 => "00000000000000000000000000000000", 
    20 => "00111100011010100010100110000011", 
    21 => "10111100100010000100010010000100", 
    22 => "10111011111011001110001110101010", 
    23 => "10111100000111111101111110010111", 
    24 => "00000000000000000000000000000000", 
    25 => "10111100000010000001011100101100", 
    26 => "10111100111111110010011000010101", 
    27 => "10111100000001111010111101001110", 
    28 => "10111001111101101111111011010110", 
    29 => "10111101000010110011100101110001", 
    30 to 31=> "00000000000000000000000000000000", 
    32 => "10111100100000000010000110101010", 
    33 => "00111011100011100111000110000011", 
    34 => "10111101001001010000110010101100", 
    35 to 36=> "00000000000000000000000000000000", 
    37 => "10111010110011011011001110010100", 
    38 => "00000000000000000000000000000000", 
    39 => "10111100010111000110000101010101", 
    40 => "00111011101100111011111011101100", 
    41 => "00000000000000000000000000000000", 
    42 => "00111100000011010110110111110011", 
    43 => "00000000000000000000000000000000", 
    44 => "00111100000111010010100011100000", 
    45 => "10111100000011001101110001110010", 
    46 => "00000000000000000000000000000000", 
    47 => "10111100001000111000111000101011", 
    48 => "10111100000000001100011110100001", 
    49 to 51=> "00000000000000000000000000000000", 
    52 => "00111100100011001001100010011101", 
    53 => "10111100110010001101110011111001", 
    54 => "10111101000101101111100010010010", 
    55 => "00000000000000000000000000000000", 
    56 => "10111100110111011111000111111111", 
    57 => "10111011010001111111000101001010", 
    58 => "10111101010100101000000010000011", 
    59 => "00000000000000000000000000000000", 
    60 => "10111100101001000111011110011010", 
    61 => "10111100010010010111000000110010", 
    62 => "10111100000001110011111000100100", 
    63 => "10111101000011001101111100001111", 
    64 => "10111101010100110011100010010111", 
    65 => "10111011111001100101001101001001", 
    66 => "00111100110000101110100110011100", 
    67 => "00000000000000000000000000000000", 
    68 => "10111100001010000010111011111101", 
    69 => "10111100110100101001100001110000", 
    70 => "10111100011011011100100010000010", 
    71 => "10111011101101000011111000111010", 
    72 => "10111101001011110011100100111000", 
    73 => "10111100101101101010000110110011", 
    74 => "00111011101010001101101110001110", 
    75 => "00000000000000000000000000000000", 
    76 => "10111100010010100001000011000010", 
    77 => "10111011110101110100111101011111", 
    78 => "10111100100101110010000010000100", 
    79 => "10111100101100100111001100101101", 
    80 => "00000000000000000000000000000000", 
    81 => "00111011001010001000101111100011", 
    82 => "10111100010111110010001000000011", 
    83 => "10111101000110011100110100000101", 
    84 => "00111100100001110010010000110101", 
    85 => "10111100001101100100001111000100", 
    86 => "10111000010100100101001111001100", 
    87 => "10111100110100001011110100000110", 
    88 => "10111011110001001011100101010100", 
    89 => "00111010111000011010010010000100", 
    90 => "00111100010100001111100000010001", 
    91 => "00111100011101010000110010000110", 
    92 => "10111011110111101001011010110000", 
    93 => "10111100100110110001000101101111", 
    94 => "00000000000000000000000000000000", 
    95 => "10111101000110110110110000101101", 
    96 => "10111100110110101000101010100001", 
    97 => "10111100001110011101001110101011", 
    98 => "00000000000000000000000000000000", 
    99 => "10111100100011010010100111010001", 
    100 => "00111011111010101001011010001010", 
    101 => "10111011001111010011101110011000", 
    102 => "10111101000010101011110111011100", 
    103 => "10111100110011111010000101101010", 
    104 => "10111011111011001101110000101111", 
    105 => "10111100011001100101011000011010", 
    106 to 108=> "00000000000000000000000000000000", 
    109 => "10111101000110111110101010000111", 
    110 => "10111100100001100100111101101001", 
    111 => "00111011110100001110111110101001" );


begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity mlp_HLS_layer1Bias is
    generic (
        DataWidth : INTEGER := 32;
        AddressRange : INTEGER := 112;
        AddressWidth : INTEGER := 7);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mlp_HLS_layer1Bias is
    component mlp_HLS_layer1Bias_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_HLS_layer1Bias_rom_U :  component mlp_HLS_layer1Bias_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;



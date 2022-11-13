// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
// Date        : Thu Oct  6 00:38:26 2022
// Host        : Teng-Dell running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ design_3_mlp_HLS_0_0_stub.v
// Design      : design_3_mlp_HLS_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xczu3eg-sbva484-1-i
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "mlp_HLS,Vivado 2020.1" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(ap_clk, ap_rst_n, S_AXIS_TVALID, S_AXIS_TREADY, 
  S_AXIS_TDATA, S_AXIS_TLAST, M_AXIS_TVALID, M_AXIS_TREADY, M_AXIS_TDATA, M_AXIS_TLAST)
/* synthesis syn_black_box black_box_pad_pin="ap_clk,ap_rst_n,S_AXIS_TVALID,S_AXIS_TREADY,S_AXIS_TDATA[31:0],S_AXIS_TLAST[0:0],M_AXIS_TVALID,M_AXIS_TREADY,M_AXIS_TDATA[31:0],M_AXIS_TLAST[0:0]" */;
  input ap_clk;
  input ap_rst_n;
  input S_AXIS_TVALID;
  output S_AXIS_TREADY;
  input [31:0]S_AXIS_TDATA;
  input [0:0]S_AXIS_TLAST;
  output M_AXIS_TVALID;
  input M_AXIS_TREADY;
  output [31:0]M_AXIS_TDATA;
  output [0:0]M_AXIS_TLAST;
endmodule

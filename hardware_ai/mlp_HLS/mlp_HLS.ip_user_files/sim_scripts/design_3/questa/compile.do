vlib questa_lib/work
vlib questa_lib/msim

vlib questa_lib/msim/xilinx_vip
vlib questa_lib/msim/xpm
vlib questa_lib/msim/lib_pkg_v1_0_2
vlib questa_lib/msim/fifo_generator_v13_2_5
vlib questa_lib/msim/lib_fifo_v1_0_14
vlib questa_lib/msim/lib_srl_fifo_v1_0_2
vlib questa_lib/msim/lib_cdc_v1_0_2
vlib questa_lib/msim/axi_datamover_v5_1_23
vlib questa_lib/msim/axi_sg_v4_1_13
vlib questa_lib/msim/axi_dma_v7_1_22
vlib questa_lib/msim/xil_defaultlib
vlib questa_lib/msim/xbip_utils_v3_0_10
vlib questa_lib/msim/axi_utils_v2_0_6
vlib questa_lib/msim/xbip_pipe_v3_0_6
vlib questa_lib/msim/xbip_dsp48_wrapper_v3_0_4
vlib questa_lib/msim/xbip_dsp48_addsub_v3_0_6
vlib questa_lib/msim/xbip_dsp48_multadd_v3_0_6
vlib questa_lib/msim/xbip_bram18k_v3_0_6
vlib questa_lib/msim/mult_gen_v12_0_16
vlib questa_lib/msim/floating_point_v7_1_10
vlib questa_lib/msim/axi_infrastructure_v1_1_0
vlib questa_lib/msim/axi_vip_v1_1_7
vlib questa_lib/msim/zynq_ultra_ps_e_vip_v1_0_7
vlib questa_lib/msim/generic_baseblocks_v2_1_0
vlib questa_lib/msim/axi_register_slice_v2_1_21
vlib questa_lib/msim/axi_data_fifo_v2_1_20
vlib questa_lib/msim/axi_crossbar_v2_1_22
vlib questa_lib/msim/proc_sys_reset_v5_0_13
vlib questa_lib/msim/xlconstant_v1_1_7
vlib questa_lib/msim/smartconnect_v1_0
vlib questa_lib/msim/axi_bram_ctrl_v4_1_3
vlib questa_lib/msim/blk_mem_gen_v8_4_4
vlib questa_lib/msim/axi_protocol_converter_v2_1_21
vlib questa_lib/msim/axi_clock_converter_v2_1_20
vlib questa_lib/msim/axi_dwidth_converter_v2_1_21

vmap xilinx_vip questa_lib/msim/xilinx_vip
vmap xpm questa_lib/msim/xpm
vmap lib_pkg_v1_0_2 questa_lib/msim/lib_pkg_v1_0_2
vmap fifo_generator_v13_2_5 questa_lib/msim/fifo_generator_v13_2_5
vmap lib_fifo_v1_0_14 questa_lib/msim/lib_fifo_v1_0_14
vmap lib_srl_fifo_v1_0_2 questa_lib/msim/lib_srl_fifo_v1_0_2
vmap lib_cdc_v1_0_2 questa_lib/msim/lib_cdc_v1_0_2
vmap axi_datamover_v5_1_23 questa_lib/msim/axi_datamover_v5_1_23
vmap axi_sg_v4_1_13 questa_lib/msim/axi_sg_v4_1_13
vmap axi_dma_v7_1_22 questa_lib/msim/axi_dma_v7_1_22
vmap xil_defaultlib questa_lib/msim/xil_defaultlib
vmap xbip_utils_v3_0_10 questa_lib/msim/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 questa_lib/msim/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 questa_lib/msim/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 questa_lib/msim/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 questa_lib/msim/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 questa_lib/msim/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 questa_lib/msim/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_16 questa_lib/msim/mult_gen_v12_0_16
vmap floating_point_v7_1_10 questa_lib/msim/floating_point_v7_1_10
vmap axi_infrastructure_v1_1_0 questa_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_7 questa_lib/msim/axi_vip_v1_1_7
vmap zynq_ultra_ps_e_vip_v1_0_7 questa_lib/msim/zynq_ultra_ps_e_vip_v1_0_7
vmap generic_baseblocks_v2_1_0 questa_lib/msim/generic_baseblocks_v2_1_0
vmap axi_register_slice_v2_1_21 questa_lib/msim/axi_register_slice_v2_1_21
vmap axi_data_fifo_v2_1_20 questa_lib/msim/axi_data_fifo_v2_1_20
vmap axi_crossbar_v2_1_22 questa_lib/msim/axi_crossbar_v2_1_22
vmap proc_sys_reset_v5_0_13 questa_lib/msim/proc_sys_reset_v5_0_13
vmap xlconstant_v1_1_7 questa_lib/msim/xlconstant_v1_1_7
vmap smartconnect_v1_0 questa_lib/msim/smartconnect_v1_0
vmap axi_bram_ctrl_v4_1_3 questa_lib/msim/axi_bram_ctrl_v4_1_3
vmap blk_mem_gen_v8_4_4 questa_lib/msim/blk_mem_gen_v8_4_4
vmap axi_protocol_converter_v2_1_21 questa_lib/msim/axi_protocol_converter_v2_1_21
vmap axi_clock_converter_v2_1_20 questa_lib/msim/axi_clock_converter_v2_1_20
vmap axi_dwidth_converter_v2_1_21 questa_lib/msim/axi_dwidth_converter_v2_1_21

vlog -work xilinx_vip  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"C:/Xilinx/Vivado/2020.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xpm  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"C:/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"C:/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"C:/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm  -93 \
"C:/Xilinx/Vivado/2020.1/data/ip/xpm/xpm_VCOMP.vhd" \

vcom -work lib_pkg_v1_0_2  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/0513/hdl/lib_pkg_v1_0_rfs.vhd" \

vlog -work fifo_generator_v13_2_5  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/276e/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_5  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/276e/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_5  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/276e/hdl/fifo_generator_v13_2_rfs.v" \

vcom -work lib_fifo_v1_0_14  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/a5cb/hdl/lib_fifo_v1_0_rfs.vhd" \

vcom -work lib_srl_fifo_v1_0_2  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/51ce/hdl/lib_srl_fifo_v1_0_rfs.vhd" \

vcom -work lib_cdc_v1_0_2  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work axi_datamover_v5_1_23  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/af86/hdl/axi_datamover_v5_1_vh_rfs.vhd" \

vcom -work axi_sg_v4_1_13  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4919/hdl/axi_sg_v4_1_rfs.vhd" \

vcom -work axi_dma_v7_1_22  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/0fb1/hdl/axi_dma_v7_1_vh_rfs.vhd" \

vcom -work xil_defaultlib  -93 \
"../../../bd/design_3/ip/design_3_axi_dma_0_0/sim/design_3_axi_dma_0_0.vhd" \

vcom -work xbip_utils_v3_0_10  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/d117/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_16  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ce84/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_10  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/248c/hdl/floating_point_v7_1_rfs.vhd" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_fadd_32nshbi.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_fcmp_32nsjbC.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_fmul_32nsibs.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_hidden1LafYi.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_layer1Bias.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_layer1Weibkb.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_layer2Bias.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_layer2Weicud.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_mux_42_32kbM.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_outputWeidEe.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS_training_eOg.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/regslice_core.v" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/verilog/mlp_HLS.v" \

vcom -work xil_defaultlib  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/ip/mlp_HLS_ap_fadd_2_full_dsp_32.vhd" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/ip/mlp_HLS_ap_fcmp_0_no_dsp_32.vhd" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/f277/hdl/ip/mlp_HLS_ap_fmul_1_max_dsp_32.vhd" \
"../../../bd/design_3/ip/design_3_mlp_HLS_0_0/sim/design_3_mlp_HLS_0_0.vhd" \

vlog -work axi_infrastructure_v1_1_0  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_7  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ce6c/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work zynq_ultra_ps_e_vip_v1_0_7  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_zynq_ultra_ps_e_0_0/sim/design_3_zynq_ultra_ps_e_0_0_vip_wrapper.v" \

vlog -work generic_baseblocks_v2_1_0  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_21  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2ef9/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work axi_data_fifo_v2_1_20  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/47c9/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_crossbar_v2_1_22  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/b68e/hdl/axi_crossbar_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_xbar_0/sim/design_3_xbar_0.v" \

vcom -work proc_sys_reset_v5_0_13  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib  -93 \
"../../../bd/design_3/ip/design_3_rst_ps8_0_99M_0/sim/design_3_rst_ps8_0_99M_0.vhd" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/sim/bd_17c8.v" \

vlog -work xlconstant_v1_1_7  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/fcfc/hdl/xlconstant_v1_1_vl_rfs.v" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_0/sim/bd_17c8_one_0.v" \

vcom -work xil_defaultlib  -93 \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_1/sim/bd_17c8_psr_aclk_0.vhd" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/sc_util_v1_0_vl_rfs.sv" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/c012/hdl/sc_switchboard_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_2/sim/bd_17c8_arsw_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_3/sim/bd_17c8_rsw_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_4/sim/bd_17c8_awsw_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_5/sim/bd_17c8_wsw_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_6/sim/bd_17c8_bsw_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/053f/hdl/sc_mmu_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_7/sim/bd_17c8_s00mmu_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_8/sim/bd_17c8_s00tr_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/9d43/hdl/sc_si_converter_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_9/sim/bd_17c8_s00sic_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_10/sim/bd_17c8_s00a2s_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/sc_node_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_11/sim/bd_17c8_sarn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_12/sim/bd_17c8_srn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_13/sim/bd_17c8_s01mmu_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_14/sim/bd_17c8_s01tr_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_15/sim/bd_17c8_s01sic_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_16/sim/bd_17c8_s01a2s_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_17/sim/bd_17c8_sawn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_18/sim/bd_17c8_swn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_19/sim/bd_17c8_sbn_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_20/sim/bd_17c8_m00s2a_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_21/sim/bd_17c8_m00arn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_22/sim/bd_17c8_m00rn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_23/sim/bd_17c8_m00awn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_24/sim/bd_17c8_m00wn_0.sv" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_25/sim/bd_17c8_m00bn_0.sv" \

vlog -work smartconnect_v1_0  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/7af8/hdl/sc_exit_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -sv -L axi_vip_v1_1_7 -L smartconnect_v1_0 -L zynq_ultra_ps_e_vip_v1_0_7 -L xilinx_vip "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/bd_0/ip/ip_26/sim/bd_17c8_m00e_0.sv" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_smc_0/sim/design_3_axi_smc_0.v" \

vcom -work axi_bram_ctrl_v4_1_3  -93 \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/db86/hdl/axi_bram_ctrl_v4_1_rfs.vhd" \

vcom -work xil_defaultlib  -93 \
"../../../bd/design_3/ip/design_3_axi_bram_ctrl_0_0/sim/design_3_axi_bram_ctrl_0_0.vhd" \

vlog -work blk_mem_gen_v8_4_4  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2985/simulation/blk_mem_gen_v8_4.v" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_axi_bram_ctrl_0_bram_0/sim/design_3_axi_bram_ctrl_0_bram_0.v" \

vlog -work axi_protocol_converter_v2_1_21  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/8dfa/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work axi_clock_converter_v2_1_20  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/7589/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work axi_dwidth_converter_v2_1_21  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/07be/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/ec67/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/e257/hdl" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/2702/hdl/verilog" "+incdir+../../../../mlp_HLS.srcs/sources_1/bd/design_3/ipshared/4676/hdl/verilog" "+incdir+C:/Xilinx/Vivado/2020.1/data/xilinx_vip/include" \
"../../../bd/design_3/ip/design_3_auto_ds_0/sim/design_3_auto_ds_0.v" \
"../../../bd/design_3/ip/design_3_auto_pc_0/sim/design_3_auto_pc_0.v" \
"../../../bd/design_3/ip/design_3_auto_ds_1/sim/design_3_auto_ds_1.v" \
"../../../bd/design_3/sim/design_3.v" \

vlog -work xil_defaultlib \
"glbl.v"


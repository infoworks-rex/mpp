/*
*
* Copyright 2015 Rockchip Electronics Co. LTD
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


#ifndef _HAL_H264D_API_H_
#define _HAL_H264D_API_H_

#include "mpp_hal.h"

typedef struct h264_mmu_t
{
	RK_U32        mmu_dte_addr;
	struct
	{
		RK_U32    pageing_enabled : 1;
		RK_U32    page_fault_active : 1;
		RK_U32    stail_active : 1;
		RK_U32    mmu_idle : 1;
		RK_U32    replay_buffer_empty1 : 1;
		RK_U32    page_fault_is_write : 1;
		RK_U32    page_fault_bus_id : 5;
		RK_U32    reserve : 8;
		//RK_U32    field0000 : 1;
	}mmu_status;
	struct
	{
		RK_U32        mmu_cmd : 3;
		RK_U32        field0000 : 1;
	}mmu_cmd;

	RK_U32        page_fault_addr;
	RK_U32        mmu_zap_one_line;
	struct int_rawstat
	{
		RK_U32    page_fault : 1;
		RK_U32    read_bus_error : 1;
	}raw_stat;
	struct int_clear
	{
		RK_U32    page_fault : 1;
		RK_U32    read_bus_error : 1;
	}clear;
	struct int_mask
	{
		RK_U32    page_fault : 1;
		RK_U32    read_bus_error : 1;
	}mask;
	struct int_status
	{
		RK_U32    page_fault : 1;
		RK_U32    read_bus_error : 1;
	}status;
	RK_U32        mmu_auto_gating : 1;
}H264_MMU_t;

typedef struct h264_cache_t
{
	struct st_version
	{
		RK_U32    version_minor : 8;
		RK_U32    version_major : 8;
		RK_U32    product_id : 16;
	}version;
	struct st_size
	{
		RK_U32    line_size : 8;
		RK_U32    associativity : 8;
		RK_U32    cache_size : 8;
		RK_U32    external_bus_width : 8;
	}size;
	struct st_status
	{
		RK_U32    cmd_busy : 1;
		RK_U32    data_busy : 1;
	}status;
	struct st_command
	{
		RK_U32    command : 4;
		RK_U32    sw_addrb_sel : 2;
	}command;
	RK_U32    clear_page;
	RK_U32    max_reads : 5;
	struct st_enable
	{
		RK_U32    permit_cacheable_access : 1;
		RK_U32    permit_cach_read_allocate : 1;
		RK_U32    sw_readbuffer_counter_reject_en : 1;
		RK_U32    sw_cache_clk_disgate : 1;
		RK_U32    sw_cache_linsize : 1;
	}enable;
	RK_U32    perfcnt_src0;
	RK_U32    perfcnt_val0;
	RK_U32    perfcnt_src1;
	RK_U32    perfcnt_val1;
}H264_CACHE_t;

typedef struct h264_regs_t
{
	struct
	{
		RK_U32    minor_ver : 8;
		RK_U32    level : 1;
		RK_U32    dec_support : 3;
		RK_U32    profile : 1;
		RK_U32    reserve0 : 1;
		RK_U32    codec_flag : 1;
		RK_U32    reserve1 : 1;
		RK_U32    prod_num : 16;
	}swreg0_id;
	struct
	{
		RK_U32    sw_dec_e : 1;//0
		RK_U32    sw_dec_clkgate_e : 1; // 1
		RK_U32    reserve0 : 1;// 2
		RK_U32    sw_timeout_mode : 1; // 3
		RK_U32    sw_dec_irq_dis : 1;//4    // 4
		RK_U32    sw_dec_timeout_e : 1; //5
		RK_U32    sw_buf_empty_en : 1; // 6
		RK_U32    sw_stmerror_waitdecfifo_empty : 1; // 7
		RK_U32    sw_dec_irq : 1; // 8
		RK_U32    sw_dec_irq_raw : 1; // 9
		RK_U32    reserve2 : 2;
		RK_U32    sw_dec_rdy_sta : 1; //12
		RK_U32    sw_dec_bus_sta : 1; //13
		RK_U32    sw_dec_error_sta : 1; // 14
		RK_U32    sw_dec_timeout_sta : 1; //15
		RK_U32    sw_dec_empty_sta : 1; // 16
		RK_U32    sw_colmv_ref_error_sta : 1; // 17
		RK_U32    sw_cabu_end_sta : 1; // 18
		RK_U32    sw_h264orvp9_error_mode : 1; //19
		RK_U32    sw_softrst_en_p : 1; //20
		RK_U32    sw_force_softreset_valid : 1; //21
		RK_U32    sw_softreset_rdy : 1; // 22
	}swreg1_int;
	struct
	{
		RK_U32    sw_in_endian : 1;
		RK_U32    sw_in_swap32_e : 1;
		RK_U32    sw_in_swap64_e : 1;
		RK_U32    sw_str_endian : 1;
		RK_U32    sw_str_swap32_e : 1;
		RK_U32    sw_str_swap64_e : 1;
		RK_U32    sw_out_endian : 1;
		RK_U32    sw_out_swap32_e : 1;
		RK_U32    sw_out_cbcr_swap : 1;
		RK_U32    reserve0 : 1;
		RK_U32    sw_rlc_mode_direct_write : 1;
		RK_U32    sw_rlc_mode : 1;
		RK_U32    sw_strm_start_bit : 7;
		RK_U32    reserve1 : 1;
		RK_U32    sw_dec_mode : 2;
		RK_U32    reserve2 : 2;
		RK_U32    sw_h264_rps_mode : 1;
		RK_U32    sw_h264_stream_mode : 1;
		RK_U32    sw_h264_stream_lastpacket : 1;
		RK_U32    sw_h264_firstslice_flag : 1;
		RK_U32    sw_h264_frame_orslice : 1;
		RK_U32    sw_buspr_slot_disable : 1;
	}swreg2_sysctrl;
	struct
	{
		RK_U32    sw_y_hor_virstride : 9;
		RK_U32    reserve : 2;
		RK_U32    sw_slice_num_highbit : 1;
		RK_U32    sw_uv_hor_virstride : 9;
		RK_U32    sw_slice_num_lowbits : 11;
	}swreg3_picpar;
	struct
	{
		RK_U32    reverse0 : 4;
		RK_U32    sw_strm_rlc_base : 28;
	}swreg4_strm_rlc_base;
	struct
	{
		RK_U32 sw_stream_len : 27;
	}swreg5_stream_rlc_len;
	struct
	{
		RK_U32    reverse0 : 4;
		RK_U32    sw_cabactbl_base : 28;
	}swreg6_cabactbl_prob_base;
	struct
	{
		RK_U32    reverse0 : 4;
		RK_U32    sw_decout_base : 28;
	}swreg7_decout_base;
	struct
	{
		RK_U32    sw_y_virstride : 20;
	}swreg8_y_virstride;
	struct
	{
		RK_U32    sw_yuv_virstride : 21;
	}swreg9_yuv_virstride;
	struct
	{
		RK_U32 sw_ref_field : 1;
		RK_U32 sw_ref_topfield_used : 1;
		RK_U32 sw_ref_botfield_used : 1;
		RK_U32 sw_ref_colmv_use_flag : 1;
		RK_U32 sw_refer_base : 28;
	}swreg10_24_refer0_14_base[15];
	RK_U32   swreg25_39_refer0_14_poc[15];
	struct
	{
		RK_U32 sw_cur_poc : 32;
	}swreg40_cur_poc;
	struct
	{
		RK_U32 reserve : 3;
		RK_U32 sw_rlcwrite_base : 29;
	}swreg41_rlcwrite_base;
	struct
	{
		RK_U32 reserve : 4;
		RK_U32 sw_pps_base : 28;
	}swreg42_pps_base;
	struct swreg_sw_rps_base
	{
		RK_U32 reserve : 4;
		RK_U32 sw_rps_base : 28;
	}swreg43_rps_base;
	struct swreg_strmd_error_e
	{
		RK_U32 sw_strmd_error_e : 28;
		RK_U32 reserve : 4;
	}swreg44_strmd_error_en;
	struct
	{
		RK_U32 sw_strmd_error_status : 28;
		RK_U32 sw_colmv_error_ref_picidx : 4;
	}swreg45_strmd_error_status;
	struct
	{
		RK_U32 sw_strmd_error_ctu_xoffset : 8;
		RK_U32 sw_strmd_error_ctu_yoffset : 8;
		RK_U32 sw_streamfifo_space2full : 7;
		RK_U32 reserve : 1;
		RK_U32 sw_vp9_error_ctu0_en : 1;
	}swreg46_strmd_error_ctu;
	struct
	{
		RK_U32 sw_saowr_xoffet : 9;
		RK_U32 reserve : 7;
		RK_U32 sw_saowr_yoffset : 10;
	}swreg47_sao_ctu_position;
	struct
	{
		RK_U32 sw_ref_field : 1;
		RK_U32 sw_ref_topfield_used : 1;
		RK_U32 sw_ref_botfield_used : 1;
		RK_U32 sw_ref_colmv_use_flag : 1;
		RK_U32 sw_refer_base : 28;
	}swreg48_refer15_base;
	RK_U32   swreg49_63_refer15_29_poc[15];
	struct
	{
		RK_U32 sw_performance_cycle : 32;
	}swreg64_performance_cycle;
	struct
	{
		RK_U32 sw_axi_ddr_rdata : 32;
	}swreg65_axi_ddr_rdata;
	struct
	{
		RK_U32 sw_axi_ddr_rdata : 32;
	}swreg66_axi_ddr_wdata;
	struct
	{
		RK_U32 sw_busifd_resetn : 1;
		RK_U32 sw_cabac_resetn : 1;
		RK_U32 sw_dec_ctrl_resetn : 1;
		RK_U32 sw_transd_resetn : 1;
		RK_U32 sw_intra_resetn : 1;
		RK_U32 sw_inter_resetn : 1;
		RK_U32 sw_recon_resetn : 1;
		RK_U32 sw_filer_resetn : 1;
	}swreg67_fpgadebug_reset;
	struct
	{
		RK_U32 perf_cnt0_sel : 6;
		RK_U32 reserve0 : 2;
		RK_U32 perf_cnt1_sel : 6;
		RK_U32 reserve1 : 2;
		RK_U32 perf_cnt2_sel : 6;
	}swreg68_performance_sel;
	struct
	{
		RK_U32 perf_cnt0 : 32;
	}swreg69_performance_cnt0;
	struct
	{
		RK_U32 perf_cnt1 : 32;
	}swreg70_performance_cnt1;
	struct
	{
		RK_U32 perf_cnt2 : 32;
	}swreg71_performance_cnt2;
	RK_U32   swreg72_refer30_poc;
	RK_U32   swreg73_refer31_poc;
	struct
	{
		RK_U32 sw_h264_cur_poc1 : 32;
	}swreg74_h264_cur_poc1;
	struct
	{
		RK_U32 reserve : 4;
		RK_U32 sw_errorinfo_base : 28;
	}swreg75_h264_errorinfo_base;
	struct
	{
		RK_U32 sw_slicedec_num : 14;
		RK_U32 reserve : 1;
		RK_U32 sw_strmd_detect_error_flag : 1;
		RK_U32 sw_error_packet_num : 14;
	}swreg76_h264_errorinfo_num;
	struct
	{
		RK_U32 sw_h264_error_en_highbits : 30;
		RK_U32 reserve : 2;
	}swreg77_h264_error_e;
	RK_U32 compare_len;
}H264_REGS_t;



//typedef struct hal_h264d_logctx_t
//{
//	struct rkv_log_flag_t  *log_flag;
//	struct rkv_log_ctx_t   *spspps;
//	struct rkv_log_ctx_t   *rps;
//	struct rkv_log_ctx_t   *scanlist;
//	struct rkv_log_ctx_t   *sodb;
//	struct rkv_log_ctx_t   *reg;
//	struct rkv_log_ctx_t   *driver;       // fwrite
//	struct rkv_log_ctx_t   *runlog;       // fprintf
//
//}HAL_H264dLogCtx_t;


//typedef struct hal_h264d_initctx_t
//{
//	HAL_H264dLogCtx_t *logctx;
//}HAL_H264dInitCtx_t;
//
//
//typedef struct hal_h264d_inctx_t
//{
//	struct h264d_syntax_t *syn;
//
//}HAL_H264dInCtx_t;
//
//typedef struct hal_h264d_outctx_t
//{
//	H264_REGS_t  *reg;
//	H264_MMU_t   *mmu;
//	H264_CACHE_t *cache;
//
//}HAL_H264dOutCtx_t;

extern const MppHalApi api_h264d_hal;

#ifdef __cplusplus
extern "C" {
#endif

	MPP_RET hal_h264d_init    (void **hal, MppHalCfg *cfg);
	MPP_RET hal_h264d_deinit  (void *hal);
	MPP_RET hal_h264d_gen_regs(void *hal, MppSyntax *syn);
	MPP_RET hal_h264d_start   (void *hal, MppHalDecTask task);
	MPP_RET hal_h264d_wait    (void *hal, MppHalDecTask task);
	MPP_RET hal_h264d_reset   (void *hal);
	MPP_RET hal_h264d_flush   (void *hal);
	MPP_RET hal_h264d_control (void *hal, RK_S32 cmd_type, void *param);



#ifdef __cplusplus
}
#endif





#endif /* _HAL_H264D_API_H_ */
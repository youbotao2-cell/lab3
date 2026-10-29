// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard.h"
#include "VDevelopmentBoard__Syms.h"

//==========

VL_CTOR_IMP(VDevelopmentBoard) {
    VDevelopmentBoard__Syms* __restrict vlSymsp = __VlSymsp = new VDevelopmentBoard__Syms(this, name());
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDevelopmentBoard::__Vconfigure(VDevelopmentBoard__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

VDevelopmentBoard::~VDevelopmentBoard() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VDevelopmentBoard::_settle__TOP__2(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_settle__TOP__2\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->h_sync = (0x60U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h));
    vlTOPp->v_sync = (2U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v));
    vlTOPp->rgb = (((IData)(vlTOPp->B2) & ((((0x90U 
                                              <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
                                             & (0x310U 
                                                > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) 
                                            & (0x23U 
                                               <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v))) 
                                           & (0x203U 
                                              > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v))))
                    ? (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_data)
                    : 0U);
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__pix_data_req 
        = ((((0x8fU <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
             & (0x30fU > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) 
            & (0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v))) 
           & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v)));
    if (vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__pix_data_req) {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x 
            = (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h) 
                         - (IData)(0x8fU)));
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y 
            = (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v) 
                         - (IData)(0x23U)));
    } else {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x = 0x3ffU;
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y = 0x3ffU;
    }
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id = 0U;
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x = 0U;
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y = 0U;
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__row_bits = 0U;
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__pixel_on = 0U;
    if (((0xd0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y)) 
         & (0x110U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y)))) {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y 
            = (7U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y) 
                      - (IData)(0xd0U)) >> 3U));
        if (((0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
             & (0xd0U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))) {
            vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id = 0U;
            vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x 
                = (7U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                          - (IData)(0x90U)) >> 3U));
        } else {
            if (((0xf0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                 & (0x130U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))) {
                vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id = 1U;
                vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x 
                    = (7U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                              - (IData)(0xf0U)) >> 3U));
            } else {
                if (((0x150U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                     & (0x190U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id = 2U;
                    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x 
                        = (7U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                  - (IData)(0x150U)) 
                                 >> 3U));
                } else {
                    if (((0x1b0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                         & (0x1f0U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))) {
                        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id = 3U;
                        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x 
                            = (7U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x) 
                                      - (IData)(0x1b0U)) 
                                     >> 3U));
                    }
                }
            }
        }
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__row_bits 
            = ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id))
                ? ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id))
                    ? ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                        ? 0x18U : ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                    ? 0x18U : ((1U 
                                                & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                                ? 0x18U
                                                : 0xffU)))
                    : ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                        ? ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                            ? ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                ? 0x7eU : 0xc3U) : 3U)
                        : ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                            ? ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                ? 0x7eU : 0xc0U) : 
                           ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                             ? 0xc3U : 0x7eU)))) : 
               ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id))
                 ? ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                     ? ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                         ? ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                             ? 0x3cU : 0xe7U) : 0xc3U)
                     : 0xc3U) : ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                  ? 0xc3U : ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                                  ? 0xdbU
                                                  : 0xffU)
                                              : ((1U 
                                                  & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y))
                                                  ? 0xe7U
                                                  : 0xc3U)))));
        if ((((((0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                & (0xd0U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))) 
               | ((0xf0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                  & (0x130U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))) 
              | ((0x150U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                 & (0x190U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)))) 
             | ((0x1b0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x)) 
                & (0x1f0U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x))))) {
            vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__pixel_on 
                = (1U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__row_bits) 
                         >> (7U & ((IData)(7U) - (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x)))));
        }
    }
}

void VDevelopmentBoard::_eval_initial(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_initial\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__B2 = vlTOPp->B2;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
}

void VDevelopmentBoard::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::final\n"); );
    // Variables
    VDevelopmentBoard__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDevelopmentBoard::_eval_settle(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_settle\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void VDevelopmentBoard::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    B2 = VL_RAND_RESET_I(1);
    B3 = VL_RAND_RESET_I(1);
    B4 = VL_RAND_RESET_I(1);
    B5 = VL_RAND_RESET_I(1);
    h_sync = VL_RAND_RESET_I(1);
    v_sync = VL_RAND_RESET_I(1);
    rgb = VL_RAND_RESET_I(16);
    led1 = VL_RAND_RESET_I(1);
    led2 = VL_RAND_RESET_I(1);
    led3 = VL_RAND_RESET_I(1);
    led4 = VL_RAND_RESET_I(1);
    led5 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_top_inst__DOT__pix_x = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_top_inst__DOT__pix_y = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_top_inst__DOT__pix_data = VL_RAND_RESET_I(16);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_id = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_x = VL_RAND_RESET_I(3);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__char_y = VL_RAND_RESET_I(3);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__row_bits = VL_RAND_RESET_I(8);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__pixel_on = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__pix_data_req = VL_RAND_RESET_I(1);
    __VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk = VL_RAND_RESET_I(1);
}

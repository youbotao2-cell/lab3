// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard.h"
#include "VDevelopmentBoard__Syms.h"

//==========

void VDevelopmentBoard::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDevelopmentBoard::eval\n"); );
    VDevelopmentBoard__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DevelopmentBoard.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDevelopmentBoard::_eval_initial_loop(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DevelopmentBoard.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__1\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = ((IData)(vlTOPp->B2) & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk)));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__3(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__3\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    // Body
    __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__pix_data 
        = ((IData)(vlTOPp->B2) ? ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_pic_inst__DOT__pixel_on)
                                   ? 0xffffU : 0U) : 0U);
    if (vlTOPp->B2) {
        if ((0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) {
            vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v 
                = ((0x20cU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v))
                    ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v))));
            __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h = 0U;
        } else {
            __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
                = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h)));
        }
    } else {
        vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v = 0U;
        __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h = 0U;
    }
    vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = __Vdly__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    vlTOPp->v_sync = (2U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_v));
    vlTOPp->h_sync = (0x60U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_ctrl_inst__DOT__cnt_h));
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

VL_INLINE_OPT void VDevelopmentBoard::_combo__TOP__4(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_combo__TOP__4\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

void VDevelopmentBoard::_eval(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((~ (IData)(vlTOPp->B2)) & (IData)(vlTOPp->__Vclklast__TOP__B2)) 
         | ((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->B2)) & (IData)(vlTOPp->__Vclklast__TOP__B2)) 
         | ((IData)(vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__B2 = vlTOPp->B2;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
    vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request_1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request_1\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk))) VL_DBG_MSGF("        CHANGE: ../vga_top.v:11: DevelopmentBoard.vga_top_inst.vga_clk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk 
        = vlTOPp->DevelopmentBoard__DOT__vga_top_inst__DOT__vga_clk;
    return __req;
}

#ifdef VL_DEBUG
void VDevelopmentBoard::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((B2 & 0xfeU))) {
        Verilated::overWidthError("B2");}
    if (VL_UNLIKELY((B3 & 0xfeU))) {
        Verilated::overWidthError("B3");}
    if (VL_UNLIKELY((B4 & 0xfeU))) {
        Verilated::overWidthError("B4");}
    if (VL_UNLIKELY((B5 & 0xfeU))) {
        Verilated::overWidthError("B5");}
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vokand.h for the primary calling header

#include "Vokand__pch.h"
#include "Vokand___024root.h"

void Vokand___024root___eval_act(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vokand___024root___nba_sequent__TOP__0(Vokand___024root* vlSelf);

void Vokand___024root___eval_nba(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vokand___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vokand___024root___nba_sequent__TOP__0(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __Vdly__okand__DOT__op_2;
    __Vdly__okand__DOT__op_2 = 0;
    SData/*15:0*/ __Vdly__okand__DOT__op_1;
    __Vdly__okand__DOT__op_1 = 0;
    CData/*4:0*/ __Vdly__okand__DOT__op_idx;
    __Vdly__okand__DOT__op_idx = 0;
    CData/*0:0*/ __Vdly__okand__DOT__do_compute;
    __Vdly__okand__DOT__do_compute = 0;
    SData/*15:0*/ __Vdly__okand__DOT__result;
    __Vdly__okand__DOT__result = 0;
    CData/*0:0*/ __Vdly__okand__DOT__do_output;
    __Vdly__okand__DOT__do_output = 0;
    CData/*3:0*/ __Vdly__okand__DOT__res_idx;
    __Vdly__okand__DOT__res_idx = 0;
    // Body
    __Vdly__okand__DOT__op_2 = vlSelfRef.okand__DOT__op_2;
    __Vdly__okand__DOT__op_1 = vlSelfRef.okand__DOT__op_1;
    __Vdly__okand__DOT__op_idx = vlSelfRef.okand__DOT__op_idx;
    __Vdly__okand__DOT__do_compute = vlSelfRef.okand__DOT__do_compute;
    __Vdly__okand__DOT__result = vlSelfRef.okand__DOT__result;
    __Vdly__okand__DOT__do_output = vlSelfRef.okand__DOT__do_output;
    __Vdly__okand__DOT__res_idx = vlSelfRef.okand__DOT__res_idx;
    if (vlSelfRef.pc_valid) {
        if ((0x10U & (IData)(vlSelfRef.okand__DOT__op_idx))) {
            __Vdly__okand__DOT__op_2 = (((~ ((IData)(1U) 
                                             << (0xfU 
                                                 & (IData)(vlSelfRef.okand__DOT__op_idx)))) 
                                         & (IData)(__Vdly__okand__DOT__op_2)) 
                                        | (0xffffU 
                                           & ((IData)(vlSelfRef.pc_data) 
                                              << (0xfU 
                                                  & (IData)(vlSelfRef.okand__DOT__op_idx)))));
        } else {
            __Vdly__okand__DOT__op_1 = (((~ ((IData)(1U) 
                                             << (0xfU 
                                                 & (IData)(vlSelfRef.okand__DOT__op_idx)))) 
                                         & (IData)(__Vdly__okand__DOT__op_1)) 
                                        | (0xffffU 
                                           & ((IData)(vlSelfRef.pc_data) 
                                              << (0xfU 
                                                  & (IData)(vlSelfRef.okand__DOT__op_idx)))));
        }
        __Vdly__okand__DOT__op_idx = (0x1fU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.okand__DOT__op_idx)));
        __Vdly__okand__DOT__do_compute = (0x1fU == (IData)(vlSelfRef.okand__DOT__op_idx));
    }
    VL_WRITEF_NX("%b %b %2#\n",0,16,vlSelfRef.okand__DOT__op_1,
                 16,(IData)(vlSelfRef.okand__DOT__op_2),
                 5,vlSelfRef.okand__DOT__op_idx);
    if (vlSelfRef.okand__DOT__do_compute) {
        __Vdly__okand__DOT__result = ((IData)(vlSelfRef.okand__DOT__op_1) 
                                      & (IData)(vlSelfRef.okand__DOT__op_2));
        __Vdly__okand__DOT__do_compute = 0U;
        __Vdly__okand__DOT__do_output = 1U;
    }
    if (vlSelfRef.okand__DOT__do_output) {
        vlSelfRef.fpga_valid = 1U;
        vlSelfRef.fpga_data = (1U & ((IData)(vlSelfRef.okand__DOT__result) 
                                     >> (IData)(vlSelfRef.okand__DOT__res_idx)));
        __Vdly__okand__DOT__res_idx = (0xfU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.okand__DOT__res_idx)));
        if ((0xfU == (IData)(vlSelfRef.okand__DOT__res_idx))) {
            __Vdly__okand__DOT__do_output = 0U;
        }
    } else {
        vlSelfRef.fpga_valid = 0U;
    }
    vlSelfRef.okand__DOT__op_2 = __Vdly__okand__DOT__op_2;
    vlSelfRef.okand__DOT__op_1 = __Vdly__okand__DOT__op_1;
    vlSelfRef.okand__DOT__op_idx = __Vdly__okand__DOT__op_idx;
    vlSelfRef.okand__DOT__do_compute = __Vdly__okand__DOT__do_compute;
    vlSelfRef.okand__DOT__result = __Vdly__okand__DOT__result;
    vlSelfRef.okand__DOT__do_output = __Vdly__okand__DOT__do_output;
    vlSelfRef.okand__DOT__res_idx = __Vdly__okand__DOT__res_idx;
}

void Vokand___024root___eval_triggers__act(Vokand___024root* vlSelf);

bool Vokand___024root___eval_phase__act(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vokand___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vokand___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vokand___024root___eval_phase__nba(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vokand___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vokand___024root___dump_triggers__nba(Vokand___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vokand___024root___dump_triggers__act(Vokand___024root* vlSelf);
#endif  // VL_DEBUG

void Vokand___024root___eval(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vokand___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("test.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vokand___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("test.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vokand___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vokand___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vokand___024root___eval_debug_assertions(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.pc_clk & 0xfeU))) {
        Verilated::overWidthError("pc_clk");}
    if (VL_UNLIKELY((vlSelfRef.pc_data & 0xfeU))) {
        Verilated::overWidthError("pc_data");}
    if (VL_UNLIKELY((vlSelfRef.pc_valid & 0xfeU))) {
        Verilated::overWidthError("pc_valid");}
}
#endif  // VL_DEBUG

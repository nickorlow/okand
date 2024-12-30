// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vokand.h for the primary calling header

#include "Vokand__pch.h"
#include "Vokand___024root.h"

VL_ATTR_COLD void Vokand___024root___eval_static(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vokand___024root___eval_initial(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__pc_clk__0 = vlSelfRef.pc_clk;
}

VL_ATTR_COLD void Vokand___024root___eval_final(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vokand___024root___eval_settle(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vokand___024root___dump_triggers__act(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge pc_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vokand___024root___dump_triggers__nba(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge pc_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vokand___024root___ctor_var_reset(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->pc_clk = VL_RAND_RESET_I(1);
    vlSelf->pc_data = VL_RAND_RESET_I(1);
    vlSelf->pc_valid = VL_RAND_RESET_I(1);
    vlSelf->fpga_data = VL_RAND_RESET_I(1);
    vlSelf->fpga_valid = VL_RAND_RESET_I(1);
    vlSelf->okand__DOT__op_1 = VL_RAND_RESET_I(16);
    vlSelf->okand__DOT__op_2 = VL_RAND_RESET_I(16);
    vlSelf->okand__DOT__op_idx = VL_RAND_RESET_I(5);
    vlSelf->okand__DOT__result = VL_RAND_RESET_I(16);
    vlSelf->okand__DOT__res_idx = VL_RAND_RESET_I(4);
    vlSelf->okand__DOT__do_compute = VL_RAND_RESET_I(1);
    vlSelf->okand__DOT__do_output = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__pc_clk__0 = VL_RAND_RESET_I(1);
}

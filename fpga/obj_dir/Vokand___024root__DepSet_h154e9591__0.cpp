// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vokand.h for the primary calling header

#include "Vokand__pch.h"
#include "Vokand__Syms.h"
#include "Vokand___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vokand___024root___dump_triggers__act(Vokand___024root* vlSelf);
#endif  // VL_DEBUG

void Vokand___024root___eval_triggers__act(Vokand___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vokand__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vokand___024root___eval_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.pc_clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pc_clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__pc_clk__0 = vlSelfRef.pc_clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vokand___024root___dump_triggers__act(vlSelf);
    }
#endif
}

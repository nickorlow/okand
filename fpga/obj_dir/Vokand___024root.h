// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vokand.h for the primary calling header

#ifndef VERILATED_VOKAND___024ROOT_H_
#define VERILATED_VOKAND___024ROOT_H_  // guard

#include "verilated.h"


class Vokand__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vokand___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(pc_clk,0,0);
    VL_IN8(pc_data,0,0);
    VL_IN8(pc_valid,0,0);
    VL_OUT8(fpga_data,0,0);
    VL_OUT8(fpga_valid,0,0);
    CData/*4:0*/ okand__DOT__op_idx;
    CData/*3:0*/ okand__DOT__res_idx;
    CData/*0:0*/ okand__DOT__do_compute;
    CData/*0:0*/ okand__DOT__do_output;
    CData/*0:0*/ __Vtrigprevexpr___TOP__pc_clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ okand__DOT__op_1;
    SData/*15:0*/ okand__DOT__op_2;
    SData/*15:0*/ okand__DOT__result;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vokand__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vokand___024root(Vokand__Syms* symsp, const char* v__name);
    ~Vokand___024root();
    VL_UNCOPYABLE(Vokand___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

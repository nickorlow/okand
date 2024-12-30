// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vokand.h for the primary calling header

#include "Vokand__pch.h"
#include "Vokand__Syms.h"
#include "Vokand___024root.h"

void Vokand___024root___ctor_var_reset(Vokand___024root* vlSelf);

Vokand___024root::Vokand___024root(Vokand__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vokand___024root___ctor_var_reset(this);
}

void Vokand___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vokand___024root::~Vokand___024root() {
}

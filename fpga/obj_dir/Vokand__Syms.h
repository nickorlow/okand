// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VOKAND__SYMS_H_
#define VERILATED_VOKAND__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vokand.h"

// INCLUDE MODULE CLASSES
#include "Vokand___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vokand__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vokand* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vokand___024root               TOP;

    // CONSTRUCTORS
    Vokand__Syms(VerilatedContext* contextp, const char* namep, Vokand* modelp);
    ~Vokand__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard

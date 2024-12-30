// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vokand__pch.h"

//============================================================
// Constructors

Vokand::Vokand(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vokand__Syms(contextp(), _vcname__, this)}
    , pc_clk{vlSymsp->TOP.pc_clk}
    , pc_data{vlSymsp->TOP.pc_data}
    , pc_valid{vlSymsp->TOP.pc_valid}
    , fpga_data{vlSymsp->TOP.fpga_data}
    , fpga_valid{vlSymsp->TOP.fpga_valid}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vokand::Vokand(const char* _vcname__)
    : Vokand(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vokand::~Vokand() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vokand___024root___eval_debug_assertions(Vokand___024root* vlSelf);
#endif  // VL_DEBUG
void Vokand___024root___eval_static(Vokand___024root* vlSelf);
void Vokand___024root___eval_initial(Vokand___024root* vlSelf);
void Vokand___024root___eval_settle(Vokand___024root* vlSelf);
void Vokand___024root___eval(Vokand___024root* vlSelf);

void Vokand::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vokand::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vokand___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vokand___024root___eval_static(&(vlSymsp->TOP));
        Vokand___024root___eval_initial(&(vlSymsp->TOP));
        Vokand___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vokand___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vokand::eventsPending() { return false; }

uint64_t Vokand::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vokand::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vokand___024root___eval_final(Vokand___024root* vlSelf);

VL_ATTR_COLD void Vokand::final() {
    Vokand___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vokand::hierName() const { return vlSymsp->name(); }
const char* Vokand::modelName() const { return "Vokand"; }
unsigned Vokand::threads() const { return 1; }
void Vokand::prepareClone() const { contextp()->prepareClone(); }
void Vokand::atClone() const {
    contextp()->threadPoolpOnClone();
}

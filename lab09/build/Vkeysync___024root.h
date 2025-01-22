// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkeysync.h for the primary calling header

#ifndef VERILATED_VKEYSYNC___024ROOT_H_
#define VERILATED_VKEYSYNC___024ROOT_H_  // guard

#include "verilated.h"


class Vkeysync__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkeysync___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(keyout,4,0);
    VL_OUT8(keyclk,0,0);
    CData/*1:0*/ keysync__DOT__delay;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(keyin,19,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vkeysync__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vkeysync___024root(Vkeysync__Syms* symsp, const char* v__name);
    ~Vkeysync___024root();
    VL_UNCOPYABLE(Vkeysync___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

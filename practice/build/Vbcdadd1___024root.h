// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vbcdadd1.h for the primary calling header

#ifndef VERILATED_VBCDADD1___024ROOT_H_
#define VERILATED_VBCDADD1___024ROOT_H_  // guard

#include "verilated.h"


class Vbcdadd1__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vbcdadd1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_IN8(cin,0,0);
    VL_OUT8(s,3,0);
    VL_OUT8(cout,0,0);
    CData/*3:0*/ bcdadd1__DOT__temp;
    CData/*4:0*/ bcdadd1__DOT__temp1;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vbcdadd1__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vbcdadd1___024root(Vbcdadd1__Syms* symsp, const char* v__name);
    ~Vbcdadd1___024root();
    VL_UNCOPYABLE(Vbcdadd1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

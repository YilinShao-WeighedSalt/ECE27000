// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vll_memory.h for the primary calling header

#ifndef VERILATED_VLL_MEMORY___024ROOT_H_
#define VERILATED_VLL_MEMORY___024ROOT_H_  // guard

#include "verilated.h"


class Vll_memory__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vll_memory___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(wen,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(alt_n,15,0);
    VL_IN16(vel_n,15,0);
    VL_IN16(fuel_n,15,0);
    VL_IN16(thrust_n,15,0);
    VL_OUT16(alt,15,0);
    VL_OUT16(vel,15,0);
    VL_OUT16(fuel,15,0);
    VL_OUT16(thrust,15,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vll_memory__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vll_memory___024root(Vll_memory__Syms* symsp, const char* v__name);
    ~Vll_memory___024root();
    VL_UNCOPYABLE(Vll_memory___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

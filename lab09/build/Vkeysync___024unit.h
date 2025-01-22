// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vkeysync.h for the primary calling header

#ifndef VERILATED_VKEYSYNC___024UNIT_H_
#define VERILATED_VKEYSYNC___024UNIT_H_  // guard

#include "verilated.h"


class Vkeysync__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vkeysync___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vkeysync__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vkeysync___024unit(Vkeysync__Syms* symsp, const char* v__name);
    ~Vkeysync___024unit();
    VL_UNCOPYABLE(Vkeysync___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

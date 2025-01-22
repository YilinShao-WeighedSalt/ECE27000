// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vll_memory.h for the primary calling header

#include "Vll_memory__pch.h"
#include "Vll_memory__Syms.h"
#include "Vll_memory___024root.h"

void Vll_memory___024root___ctor_var_reset(Vll_memory___024root* vlSelf);

Vll_memory___024root::Vll_memory___024root(Vll_memory__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vll_memory___024root___ctor_var_reset(this);
}

void Vll_memory___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vll_memory___024root::~Vll_memory___024root() {
}

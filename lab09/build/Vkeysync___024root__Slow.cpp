// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeysync.h for the primary calling header

#include "Vkeysync__pch.h"
#include "Vkeysync__Syms.h"
#include "Vkeysync___024root.h"

void Vkeysync___024root___ctor_var_reset(Vkeysync___024root* vlSelf);

Vkeysync___024root::Vkeysync___024root(Vkeysync__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vkeysync___024root___ctor_var_reset(this);
}

void Vkeysync___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vkeysync___024root::~Vkeysync___024root() {
}

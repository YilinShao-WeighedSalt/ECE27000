// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeysync.h for the primary calling header

#include "Vkeysync__pch.h"
#include "Vkeysync__Syms.h"
#include "Vkeysync___024unit.h"

void Vkeysync___024unit___ctor_var_reset(Vkeysync___024unit* vlSelf);

Vkeysync___024unit::Vkeysync___024unit(Vkeysync__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vkeysync___024unit___ctor_var_reset(this);
}

void Vkeysync___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vkeysync___024unit::~Vkeysync___024unit() {
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vll_memory.h for the primary calling header

#include "Vll_memory__pch.h"
#include "Vll_memory__Syms.h"
#include "Vll_memory___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vll_memory___024root___dump_triggers__act(Vll_memory___024root* vlSelf);
#endif  // VL_DEBUG

void Vll_memory___024root___eval_triggers__act(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vll_memory___024root___dump_triggers__act(vlSelf);
    }
#endif
}

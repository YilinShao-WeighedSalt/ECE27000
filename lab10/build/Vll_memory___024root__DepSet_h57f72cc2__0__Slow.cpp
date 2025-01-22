// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vll_memory.h for the primary calling header

#include "Vll_memory__pch.h"
#include "Vll_memory___024root.h"

VL_ATTR_COLD void Vll_memory___024root___eval_static(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vll_memory___024root___eval_initial(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vll_memory___024root___eval_final(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vll_memory___024root___eval_settle(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vll_memory___024root___dump_triggers__act(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vll_memory___024root___dump_triggers__nba(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vll_memory___024root___ctor_var_reset(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->wen = VL_RAND_RESET_I(1);
    vlSelf->alt_n = VL_RAND_RESET_I(16);
    vlSelf->vel_n = VL_RAND_RESET_I(16);
    vlSelf->fuel_n = VL_RAND_RESET_I(16);
    vlSelf->thrust_n = VL_RAND_RESET_I(16);
    vlSelf->alt = VL_RAND_RESET_I(16);
    vlSelf->vel = VL_RAND_RESET_I(16);
    vlSelf->fuel = VL_RAND_RESET_I(16);
    vlSelf->thrust = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}

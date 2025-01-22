// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vll_memory.h for the primary calling header

#include "Vll_memory__pch.h"
#include "Vll_memory___024root.h"

void Vll_memory___024root___eval_act(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vll_memory___024root___nba_sequent__TOP__0(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst) {
        vlSelf->thrust = 5U;
        vlSelf->fuel = 0x800U;
        vlSelf->vel = 0U;
        vlSelf->alt = 0x4500U;
    } else if (vlSelf->wen) {
        vlSelf->thrust = vlSelf->thrust_n;
        vlSelf->fuel = vlSelf->fuel_n;
        vlSelf->vel = vlSelf->vel_n;
        vlSelf->alt = vlSelf->alt_n;
    }
}

void Vll_memory___024root___eval_nba(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vll_memory___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vll_memory___024root___eval_triggers__act(Vll_memory___024root* vlSelf);

bool Vll_memory___024root___eval_phase__act(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vll_memory___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vll_memory___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vll_memory___024root___eval_phase__nba(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vll_memory___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vll_memory___024root___dump_triggers__nba(Vll_memory___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vll_memory___024root___dump_triggers__act(Vll_memory___024root* vlSelf);
#endif  // VL_DEBUG

void Vll_memory___024root___eval(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vll_memory___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 178, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vll_memory___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 178, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vll_memory___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vll_memory___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vll_memory___024root___eval_debug_assertions(Vll_memory___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wen & 0xfeU))) {
        Verilated::overWidthError("wen");}
}
#endif  // VL_DEBUG

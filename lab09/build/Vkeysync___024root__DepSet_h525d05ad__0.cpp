// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeysync.h for the primary calling header

#include "Vkeysync__pch.h"
#include "Vkeysync___024root.h"

VL_INLINE_OPT void Vkeysync___024root___ico_sequent__TOP__0(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->keyout = (((IData)((0U != (0xfU & (vlSelf->keyin 
                                               >> 0x10U)))) 
                       << 4U) | (((IData)((0U != (0xffU 
                                                  & (vlSelf->keyin 
                                                     >> 8U)))) 
                                  << 3U) | (((IData)(
                                                     (0U 
                                                      != 
                                                      (0xf0f0U 
                                                       & vlSelf->keyin))) 
                                             << 2U) 
                                            | (((IData)(
                                                        (0U 
                                                         != 
                                                         (0xcccccU 
                                                          & vlSelf->keyin))) 
                                                << 1U) 
                                               | (IData)(
                                                         (0U 
                                                          != 
                                                          (0xaaaaaU 
                                                           & vlSelf->keyin)))))));
}

void Vkeysync___024root___eval_ico(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vkeysync___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vkeysync___024root___eval_triggers__ico(Vkeysync___024root* vlSelf);

bool Vkeysync___024root___eval_phase__ico(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vkeysync___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vkeysync___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vkeysync___024root___eval_act(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vkeysync___024root___nba_sequent__TOP__0(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->keysync__DOT__delay = ((IData)(vlSelf->rst)
                                    ? 0U : (3U & (VL_SHIFTL_III(2,2,32, (IData)(vlSelf->keysync__DOT__delay), 1U) 
                                                  | (0U 
                                                     != vlSelf->keyin))));
    vlSelf->keyclk = (1U & ((IData)(vlSelf->keysync__DOT__delay) 
                            >> 1U));
}

void Vkeysync___024root___eval_nba(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vkeysync___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vkeysync___024root___eval_triggers__act(Vkeysync___024root* vlSelf);

bool Vkeysync___024root___eval_phase__act(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vkeysync___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vkeysync___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vkeysync___024root___eval_phase__nba(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vkeysync___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__ico(Vkeysync___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__nba(Vkeysync___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__act(Vkeysync___024root* vlSelf);
#endif  // VL_DEBUG

void Vkeysync___024root___eval(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vkeysync___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 80, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vkeysync___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vkeysync___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 80, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vkeysync___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.sv", 80, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vkeysync___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vkeysync___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vkeysync___024root___eval_debug_assertions(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->keyin & 0xfff00000U))) {
        Verilated::overWidthError("keyin");}
}
#endif  // VL_DEBUG

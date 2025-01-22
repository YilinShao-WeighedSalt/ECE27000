// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkeysync.h for the primary calling header

#include "Vkeysync__pch.h"
#include "Vkeysync___024root.h"

VL_ATTR_COLD void Vkeysync___024root___eval_static(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vkeysync___024root___eval_initial(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void Vkeysync___024root___eval_final(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__stl(Vkeysync___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vkeysync___024root___eval_phase__stl(Vkeysync___024root* vlSelf);

VL_ATTR_COLD void Vkeysync___024root___eval_settle(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vkeysync___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("top.sv", 80, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vkeysync___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__stl(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkeysync___024root___stl_sequent__TOP__0(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___stl_sequent__TOP__0\n"); );
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
    vlSelf->keyclk = (1U & ((IData)(vlSelf->keysync__DOT__delay) 
                            >> 1U));
}

VL_ATTR_COLD void Vkeysync___024root___eval_stl(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vkeysync___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vkeysync___024root___eval_triggers__stl(Vkeysync___024root* vlSelf);

VL_ATTR_COLD bool Vkeysync___024root___eval_phase__stl(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vkeysync___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vkeysync___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__ico(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__act(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkeysync___024root___dump_triggers__nba(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vkeysync___024root___ctor_var_reset(Vkeysync___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->keyin = VL_RAND_RESET_I(20);
    vlSelf->keyout = VL_RAND_RESET_I(5);
    vlSelf->keyclk = VL_RAND_RESET_I(1);
    vlSelf->keysync__DOT__delay = VL_RAND_RESET_I(2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}

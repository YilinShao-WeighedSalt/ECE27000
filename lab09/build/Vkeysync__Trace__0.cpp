// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vkeysync__Syms.h"


void Vkeysync___024root__trace_chg_0_sub_0(Vkeysync___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vkeysync___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root__trace_chg_0\n"); );
    // Init
    Vkeysync___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkeysync___024root*>(voidSelf);
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vkeysync___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vkeysync___024root__trace_chg_0_sub_0(Vkeysync___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgIData(oldp+2,(vlSelf->keyin),20);
    bufp->chgCData(oldp+3,(vlSelf->keyout),5);
    bufp->chgBit(oldp+4,(vlSelf->keyclk));
    bufp->chgCData(oldp+5,(vlSelf->keysync__DOT__delay),2);
}

void Vkeysync___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkeysync___024root__trace_cleanup\n"); );
    // Init
    Vkeysync___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkeysync___024root*>(voidSelf);
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}

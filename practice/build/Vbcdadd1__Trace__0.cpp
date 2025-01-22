// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vbcdadd1__Syms.h"


void Vbcdadd1___024root__trace_chg_0_sub_0(Vbcdadd1___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vbcdadd1___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_chg_0\n"); );
    // Init
    Vbcdadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcdadd1___024root*>(voidSelf);
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vbcdadd1___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vbcdadd1___024root__trace_chg_0_sub_0(Vbcdadd1___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->a),4);
    bufp->chgCData(oldp+1,(vlSelf->b),4);
    bufp->chgBit(oldp+2,(vlSelf->cin));
    bufp->chgCData(oldp+3,(vlSelf->s),4);
    bufp->chgBit(oldp+4,(vlSelf->cout));
    bufp->chgCData(oldp+5,(vlSelf->bcdadd1__DOT__temp),4);
    bufp->chgCData(oldp+6,(vlSelf->bcdadd1__DOT__temp1),5);
}

void Vbcdadd1___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_cleanup\n"); );
    // Init
    Vbcdadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcdadd1___024root*>(voidSelf);
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}

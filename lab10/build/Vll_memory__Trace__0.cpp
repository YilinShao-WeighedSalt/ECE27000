// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vll_memory__Syms.h"


void Vll_memory___024root__trace_chg_0_sub_0(Vll_memory___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vll_memory___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root__trace_chg_0\n"); );
    // Init
    Vll_memory___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vll_memory___024root*>(voidSelf);
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vll_memory___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vll_memory___024root__trace_chg_0_sub_0(Vll_memory___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgBit(oldp+2,(vlSelf->wen));
    bufp->chgSData(oldp+3,(vlSelf->alt_n),16);
    bufp->chgSData(oldp+4,(vlSelf->vel_n),16);
    bufp->chgSData(oldp+5,(vlSelf->fuel_n),16);
    bufp->chgSData(oldp+6,(vlSelf->thrust_n),16);
    bufp->chgSData(oldp+7,(vlSelf->alt),16);
    bufp->chgSData(oldp+8,(vlSelf->vel),16);
    bufp->chgSData(oldp+9,(vlSelf->fuel),16);
    bufp->chgSData(oldp+10,(vlSelf->thrust),16);
}

void Vll_memory___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vll_memory___024root__trace_cleanup\n"); );
    // Init
    Vll_memory___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vll_memory___024root*>(voidSelf);
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}

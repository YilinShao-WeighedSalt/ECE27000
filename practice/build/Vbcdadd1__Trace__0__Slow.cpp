// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vbcdadd1__Syms.h"


VL_ATTR_COLD void Vbcdadd1___024root__trace_init_sub__TOP__0(Vbcdadd1___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+2,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+3,0,"cin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+5,0,"cout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("bcdadd1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+2,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+3,0,"cin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+5,0,"cout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"temp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+7,0,"temp1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbcdadd1___024root__trace_init_top(Vbcdadd1___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_init_top\n"); );
    // Body
    Vbcdadd1___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vbcdadd1___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vbcdadd1___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vbcdadd1___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vbcdadd1___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vbcdadd1___024root__trace_register(Vbcdadd1___024root* vlSelf, VerilatedFst* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vbcdadd1___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vbcdadd1___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vbcdadd1___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vbcdadd1___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vbcdadd1___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_const_0\n"); );
    // Init
    Vbcdadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcdadd1___024root*>(voidSelf);
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vbcdadd1___024root__trace_full_0_sub_0(Vbcdadd1___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vbcdadd1___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_full_0\n"); );
    // Init
    Vbcdadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcdadd1___024root*>(voidSelf);
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vbcdadd1___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vbcdadd1___024root__trace_full_0_sub_0(Vbcdadd1___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbcdadd1___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->a),4);
    bufp->fullCData(oldp+2,(vlSelf->b),4);
    bufp->fullBit(oldp+3,(vlSelf->cin));
    bufp->fullCData(oldp+4,(vlSelf->s),4);
    bufp->fullBit(oldp+5,(vlSelf->cout));
    bufp->fullCData(oldp+6,(vlSelf->bcdadd1__DOT__temp),4);
    bufp->fullCData(oldp+7,(vlSelf->bcdadd1__DOT__temp1),5);
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbcdadd1__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vbcdadd1::Vbcdadd1(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbcdadd1__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , cin{vlSymsp->TOP.cin}
    , s{vlSymsp->TOP.s}
    , cout{vlSymsp->TOP.cout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vbcdadd1::Vbcdadd1(const char* _vcname__)
    : Vbcdadd1(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbcdadd1::~Vbcdadd1() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbcdadd1___024root___eval_debug_assertions(Vbcdadd1___024root* vlSelf);
#endif  // VL_DEBUG
void Vbcdadd1___024root___eval_static(Vbcdadd1___024root* vlSelf);
void Vbcdadd1___024root___eval_initial(Vbcdadd1___024root* vlSelf);
void Vbcdadd1___024root___eval_settle(Vbcdadd1___024root* vlSelf);
void Vbcdadd1___024root___eval(Vbcdadd1___024root* vlSelf);

void Vbcdadd1::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbcdadd1::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbcdadd1___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbcdadd1___024root___eval_static(&(vlSymsp->TOP));
        Vbcdadd1___024root___eval_initial(&(vlSymsp->TOP));
        Vbcdadd1___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbcdadd1___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vbcdadd1::eventsPending() { return false; }

uint64_t Vbcdadd1::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vbcdadd1::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbcdadd1___024root___eval_final(Vbcdadd1___024root* vlSelf);

VL_ATTR_COLD void Vbcdadd1::final() {
    Vbcdadd1___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbcdadd1::hierName() const { return vlSymsp->name(); }
const char* Vbcdadd1::modelName() const { return "Vbcdadd1"; }
unsigned Vbcdadd1::threads() const { return 1; }
void Vbcdadd1::prepareClone() const { contextp()->prepareClone(); }
void Vbcdadd1::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vbcdadd1::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vbcdadd1___024root__trace_decl_types(VerilatedFst* tracep);

void Vbcdadd1___024root__trace_init_top(Vbcdadd1___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbcdadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbcdadd1___024root*>(voidSelf);
    Vbcdadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vbcdadd1___024root__trace_decl_types(tracep);
    Vbcdadd1___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbcdadd1___024root__trace_register(Vbcdadd1___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vbcdadd1::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbcdadd1::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vbcdadd1___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

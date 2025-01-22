// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vkeysync__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vkeysync::Vkeysync(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vkeysync__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , keyout{vlSymsp->TOP.keyout}
    , keyclk{vlSymsp->TOP.keyclk}
    , keyin{vlSymsp->TOP.keyin}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vkeysync::Vkeysync(const char* _vcname__)
    : Vkeysync(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vkeysync::~Vkeysync() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vkeysync___024root___eval_debug_assertions(Vkeysync___024root* vlSelf);
#endif  // VL_DEBUG
void Vkeysync___024root___eval_static(Vkeysync___024root* vlSelf);
void Vkeysync___024root___eval_initial(Vkeysync___024root* vlSelf);
void Vkeysync___024root___eval_settle(Vkeysync___024root* vlSelf);
void Vkeysync___024root___eval(Vkeysync___024root* vlSelf);

void Vkeysync::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vkeysync::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vkeysync___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vkeysync___024root___eval_static(&(vlSymsp->TOP));
        Vkeysync___024root___eval_initial(&(vlSymsp->TOP));
        Vkeysync___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vkeysync___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vkeysync::eventsPending() { return false; }

uint64_t Vkeysync::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vkeysync::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vkeysync___024root___eval_final(Vkeysync___024root* vlSelf);

VL_ATTR_COLD void Vkeysync::final() {
    Vkeysync___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vkeysync::hierName() const { return vlSymsp->name(); }
const char* Vkeysync::modelName() const { return "Vkeysync"; }
unsigned Vkeysync::threads() const { return 1; }
void Vkeysync::prepareClone() const { contextp()->prepareClone(); }
void Vkeysync::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vkeysync::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vkeysync___024root__trace_decl_types(VerilatedFst* tracep);

void Vkeysync___024root__trace_init_top(Vkeysync___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vkeysync___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkeysync___024root*>(voidSelf);
    Vkeysync__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vkeysync___024root__trace_decl_types(tracep);
    Vkeysync___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vkeysync___024root__trace_register(Vkeysync___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vkeysync::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vkeysync::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vkeysync___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

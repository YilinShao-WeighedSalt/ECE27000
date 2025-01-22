// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vll_memory__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vll_memory::Vll_memory(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vll_memory__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , wen{vlSymsp->TOP.wen}
    , alt_n{vlSymsp->TOP.alt_n}
    , vel_n{vlSymsp->TOP.vel_n}
    , fuel_n{vlSymsp->TOP.fuel_n}
    , thrust_n{vlSymsp->TOP.thrust_n}
    , alt{vlSymsp->TOP.alt}
    , vel{vlSymsp->TOP.vel}
    , fuel{vlSymsp->TOP.fuel}
    , thrust{vlSymsp->TOP.thrust}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vll_memory::Vll_memory(const char* _vcname__)
    : Vll_memory(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vll_memory::~Vll_memory() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vll_memory___024root___eval_debug_assertions(Vll_memory___024root* vlSelf);
#endif  // VL_DEBUG
void Vll_memory___024root___eval_static(Vll_memory___024root* vlSelf);
void Vll_memory___024root___eval_initial(Vll_memory___024root* vlSelf);
void Vll_memory___024root___eval_settle(Vll_memory___024root* vlSelf);
void Vll_memory___024root___eval(Vll_memory___024root* vlSelf);

void Vll_memory::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vll_memory::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vll_memory___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vll_memory___024root___eval_static(&(vlSymsp->TOP));
        Vll_memory___024root___eval_initial(&(vlSymsp->TOP));
        Vll_memory___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vll_memory___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vll_memory::eventsPending() { return false; }

uint64_t Vll_memory::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vll_memory::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vll_memory___024root___eval_final(Vll_memory___024root* vlSelf);

VL_ATTR_COLD void Vll_memory::final() {
    Vll_memory___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vll_memory::hierName() const { return vlSymsp->name(); }
const char* Vll_memory::modelName() const { return "Vll_memory"; }
unsigned Vll_memory::threads() const { return 1; }
void Vll_memory::prepareClone() const { contextp()->prepareClone(); }
void Vll_memory::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vll_memory::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vll_memory___024root__trace_decl_types(VerilatedFst* tracep);

void Vll_memory___024root__trace_init_top(Vll_memory___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vll_memory___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vll_memory___024root*>(voidSelf);
    Vll_memory__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vll_memory___024root__trace_decl_types(tracep);
    Vll_memory___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vll_memory___024root__trace_register(Vll_memory___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vll_memory::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vll_memory::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    (void)levels; (void)options; // Prevent unused variable warning
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vll_memory___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

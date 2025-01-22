// Lab practical testbench
// Do not modify this file.  We will use our own copy of this 
// file to autograde your Verilog after you leave.
// 
// You are still welcome to look through to learn how to write 
// Verilog testbenches in C++ using Verilator.
//======================================================================

#include <verilated.h>
#include "verilated_fst_c.h"
#include <iostream>
#include <random>

const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
VerilatedFstC* tfp = new VerilatedFstC;

static int passed_tests = 0;
static int total_tests = 0;

int inv(int a) {
    return a ^ 1;
}

int pin(int a, int b) {
  return (a >> b) & 1;
}

int pinsel(int x, int a, int b) {
    assert(a < b);
    int y = 0;
    for (int i = a; i <= b; i++) {
        y |= pin(x, i);
    }
    return y;
}

std::string padbin (int x, int n) {
    std::string s = std::bitset<32>(x).to_string();
    return s.substr(s.size() - n);
}

template <typename T>
void eval(T* model) {
    contextp->timeInc(1);
    model->eval();
    tfp->dump(contextp->time());
}

template <typename T>
void assert_clock(T* model) {
    model->clk = 1; eval(model);
}

template <typename T>
void deassert_clock(T* model) {
    model->clk = 0; eval(model);
}

template <typename T>
void cycle_clock(T* model) {
    assert_clock(model);
    deassert_clock(model);
}

#if defined(TFF) 
    #include "Vtff.h"
    #define POINTS 10
#elif defined(RING)
    #include "Vring.h"
    #define POINTS 30
#elif defined(DECIMAL)
    #include "Vdecimal.h"
    #define POINTS 30
#elif defined(BCDADD1)
    #include "Vbcdadd1.h"
    #define POINTS 30
#endif

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    #if defined(TFF)
        std::cout << "Testing tff...\n";
        // Construct the Verilated model, from each module after Verilating each module file
        const std::unique_ptr<Vtff> tff {new Vtff {contextp.get(), "tff"} };
        tff->trace(tfp, 99);
        tfp->open("tff.fst");

        // Init all ports
        tff->clk = 0;
        tff->rst = 0;
        tff->T = 0;

        // Reset and test the model
        total_tests++;
        std::cout << "\n1. Asserting reset...\n";
        tff->rst = 0; eval(tff.get());
        tff->rst = 1; eval(tff.get());
        tff->rst = 0; eval(tff.get());
        if (tff->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: tff->Q should be 0, not " << tff->Q << ".\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: tff->Q is 0.\n";
            passed_tests++;
        }

        // Test the model
        total_tests++;
        std::cout << "\n2. Cycling clock when T == 0\n";
        tff->T = 0; eval(tff.get());
        cycle_clock(tff.get());
        if (tff->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: tff->Q should be 0, not " << tff->Q << "while tff->T == 0.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: tff->Q is 0 when tff->T == 0.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n3. Cycling clock when T == 1\n";
        tff->T = 1; eval(tff.get());
        cycle_clock(tff.get());
        if (tff->Q != 1) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: tff->Q should be 1, not " << tff->Q << "while tff->T == 1.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: tff->Q is 1 when tff->T == 1 after one clock cycle.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n4. Cycling clock when T == 1, tff->Q should now be 0\n";
        tff->T = 1; eval(tff.get());
        cycle_clock(tff.get());
        if (tff->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: tff->Q should be 0, not " << tff->Q << "while tff->T == 1.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: tff->Q is 0 when tff->T == 1 after two clock cycles.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n5. Cycling clock when T == 1, tff->Q should be 1 again\n";
        tff->T = 1; eval(tff.get());
        cycle_clock(tff.get());
        if (tff->Q != 1) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: tff->Q should be 1, not " << tff->Q << "while tff->T == 1.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: tff->Q is 1 when tff->T == 1 after three clock cycles.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n6. Asynchronous reset of tff, tff->Q should be 0 regardless of clock\n";
        tff->rst = 1; eval(tff.get());
        cycle_clock(tff.get());
        cycle_clock(tff.get());
        tff->rst = 0; eval(tff.get());
        if (tff->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: tff->Q should be 0 after asynchronous reset.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: tff->Q is 0 after asynchronous reset.\n";
            passed_tests++;
        }

    #elif defined(RING)
        std::cout << "Testing ring...\n";
        // Construct the Verilated model, from each module after Verilating each module file
        const std::unique_ptr<Vring> ring {new Vring {contextp.get(), "ring"} };
        ring->trace(tfp, 99);
        tfp->open("ring.fst");

        // Init all ports
        ring->clk = 0;  
        ring->rst = 0;
        ring->en = 0;

        // Reset and test the model
        total_tests++;
        std::cout << "\n1. Asserting reset...\n";
        ring->rst = 0; eval(ring.get());
        ring->rst = 1; eval(ring.get());
        ring->rst = 0; eval(ring.get());
        if (ring->Q != 1) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be 00000001, not " << padbin(ring->Q, 8) << ".\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is 00000001.\n";
            passed_tests++;
        }

        // Test the model
        total_tests++;
        std::cout << "\n2. Cycling clock when en == 0\n";
        ring->en = 0; eval(ring.get());
        cycle_clock(ring.get());
        if (ring->Q != 1) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be 00000001, not " << padbin(ring->Q, 8) << " while ring->en == 0.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is 00000001 while ring->en == 0.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n3. Cycling clock when en == 1\n";
        ring->en = 1; eval(ring.get());
        cycle_clock(ring.get());
        if (ring->Q != 2) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be 00000010, not " << padbin(ring->Q, 8) << " while ring->en == 1.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is 00000010 while ring->en == 1.\n";
            passed_tests++;
        }

        for (int i = 2; i <= 7; i++) {
            total_tests++;
            std::cout << "\n" << i+2 << ". Cycling clock when en == 1\n";
            ring->en = 1; eval(ring.get());
            cycle_clock(ring.get());
            if (ring->Q != (1 << i)) {
                std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be " << padbin(1 << i, 8) << ", not " << padbin(ring->Q, 8) << " while ring->en == 1.\n";
            } else {
                std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is " << padbin(1 << i, 8) << " while ring->en == 1.\n";
                passed_tests++;
            }
        }

        total_tests++;
        std::cout << "\n10. Cycling clock when en == 1, ring->Q should now be 00000001\n";
        ring->en = 1; eval(ring.get());
        cycle_clock(ring.get());
        if (ring->Q != 1) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be 00000001, not " << padbin(ring->Q, 8) << " while ring->en == 1.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is 00000001 while ring->en == 1.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n11. Cycling clock when en == 1, ring->Q should now be 00000010\n";
        ring->en = 1; eval(ring.get());
        cycle_clock(ring.get());
        if (ring->Q != 2) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be 00000010, not " << padbin(ring->Q, 8) << " while ring->en == 1.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is 00000010 while ring->en == 1.\n";
            passed_tests++;
        }

        total_tests++;
        std::cout << "\n12. Asserting asynchronous reset, ring->Q should now be 00000001\n";
        ring->rst = 1; eval(ring.get());
        cycle_clock(ring.get());
        cycle_clock(ring.get());
        ring->rst = 0; eval(ring.get());
        if (ring->Q != 1) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: ring->Q should be 00000001 after asynchronous reset.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: ring->Q is 00000001 after asynchronous reset.\n";
            passed_tests++;
        }

    #elif defined(DECIMAL)
        std::cout << "Testing decimal...\n";
        // Construct the Verilated model, from each module after Verilating each module file
        const std::unique_ptr<Vdecimal> decimal {new Vdecimal {contextp.get(), "decimal"} };
        decimal->trace(tfp, 99);
        tfp->open("decimal.fst");

        // Init all ports
        decimal->clk = 0;  
        decimal->rst = 0;
        decimal->en = 0;

        // Reset and test the model
        total_tests++;
        std::cout << "\n1. Asserting reset...\n";
        decimal->rst = 0; eval(decimal.get());
        decimal->rst = 1; eval(decimal.get());
        decimal->rst = 0; eval(decimal.get());
        if (decimal->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: decimal->Q should be 0, not " << decimal->Q << ".\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: decimal->Q is 0.\n";
            passed_tests++;
        }

        // Test the model
        total_tests++;
        std::cout << "\n2. Cycling clock when en == 0\n";
        decimal->en = 0; eval(decimal.get());
        cycle_clock(decimal.get());
        if (decimal->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: decimal->Q should be 0, not " << padbin(decimal->Q, 4) << " while decimal->en == 0.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: decimal->Q is 0 while decimal->en == 0.\n";
            passed_tests++;
        }

        for (int i = 0; i < 20; i++) {
            total_tests++;
            std::cout << "\n" << i+3 << ". Cycling clock when en == 1\n";
            decimal->en = 1; eval(decimal.get());
            cycle_clock(decimal.get());
            if (decimal->Q != ((i+1) % 10)) {
                std::cout << "(" << contextp->time() << " sec) " << "Failed test: decimal->Q should be " << ((i+1) % 10) << ", not " << std::to_string(decimal->Q) << " while decimal->en == 1.\n";
            } else {
                std::cout << "(" << contextp->time() << " sec) " << "Passed test: decimal->Q is " << std::to_string(decimal->Q) << " while decimal->en == 1.\n";
                passed_tests++;
            }
        }

        total_tests++;
        std::cout << "\n23. Asserting asynchronous reset, decimal->Q should now be 0\n";
        decimal->rst = 1; eval(decimal.get());
        cycle_clock(decimal.get());
        cycle_clock(decimal.get());
        decimal->rst = 0; eval(decimal.get());
        if (decimal->Q != 0) {
            std::cout << "(" << contextp->time() << " sec) " << "Failed test: decimal->Q should be 0 after asynchronous reset.\n";
        } else {
            std::cout << "(" << contextp->time() << " sec) " << "Passed test: decimal->Q is 0 after asynchronous reset.\n";
            passed_tests++;
        }

    #elif defined(BCDADD1)
        std::cout << "Testing bcdadd1...\n";
        // Construct the Verilated model, from each module after Verilating each module file
        const std::unique_ptr<Vbcdadd1> bcdadd1 {new Vbcdadd1 {contextp.get(), "bcdadd1"} };
        bcdadd1->trace(tfp, 99);
        tfp->open("bcdadd1.fst");

        // Init all ports
        bcdadd1->a = 0;  
        bcdadd1->b = 0;
        bcdadd1->cin = 0;
        // outputs are [3:0]s and cout

        for (bcdadd1->a = 0; bcdadd1->a <= 9; bcdadd1->a++) {
            for (bcdadd1->b = 0; bcdadd1->b <= 9; bcdadd1->b++) {
                for (bcdadd1->cin = 0; bcdadd1->cin <= 1; bcdadd1->cin++) {
                    uint32_t s = bcdadd1->a + bcdadd1->b + bcdadd1->cin;
                    uint32_t expected_s = s % 10;
                    uint32_t expected_cout = s / 10;
                    std::cout << "\n" << total_tests << ". Adding a = " << std::to_string(bcdadd1->a) << ", b = " << std::to_string(bcdadd1->b) << ", cin = " << std::to_string(bcdadd1->cin);
                    std::cout << ", expected BCD sum = " << std::to_string(s) << ".\n";
                    eval(bcdadd1.get());
                    total_tests++;
                    if (bcdadd1->s != expected_s) {
                        std::cout << "(" << contextp->time() << " sec) " << "Failed test: bcdadd1->s should be " << expected_s << ", not " << std::to_string(bcdadd1->s) << ".\n";
                    } else {
                        std::cout << "(" << contextp->time() << " sec) " << "Passed test: bcdadd1->s is " << expected_s << ".\n";
                        passed_tests++;
                    }
                    total_tests++;
                    if (bcdadd1->cout != expected_cout) {
                        std::cout << "(" << contextp->time() << " sec) " << "Failed test: bcdadd1->cout should be " << expected_cout << ", not " << std::to_string(bcdadd1->cout) << ".\n";
                    } else {
                        std::cout << "(" << contextp->time() << " sec) " << "Passed test: bcdadd1->cout is " << expected_cout << ".\n";
                        passed_tests++;
                    }
                }
            }
        }
    
    #else
        std::cout << "No module defined.\n";
        return 1;
    #endif

    // Print out results
    std::cout << "\nPassed " << passed_tests << "/" << total_tests << " tests.\n";
    // Scale to points
    std::cout << "tff score: " << (passed_tests * POINTS) / total_tests << "/" << POINTS << "\n";
    // Close wave dump
    tfp->close();

    return 0;
}
#include "benchmark/benchmark.h"
#include <iostream>
 
int get_day_switch(int day) {
    switch (day) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        case 4: return 4;
        case 5: return 5;
        case 6: return 6;
        case 7: return 7;
        default: return 0;
    }
}
 
int get_day_ifelse(int day) {
    if (day == 1) return 1;
    else if (day == 2) return 2;
    else if (day == 3) return 3;
    else if (day == 4) return 4;
    else if (day == 5) return 5;
    else if (day == 6) return 6;
    else if (day == 7) return 7;
    else return 0;
}
 
static void BM_Switch(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(get_day_switch(state.range(0)));
    }
}
BENCHMARK(BM_Switch)->Arg(4);
 
static void BM_IfElse(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(get_day_ifelse(state.range(0)));
    }
}
BENCHMARK(BM_IfElse)->Arg(4);
 
BENCHMARK_MAIN();
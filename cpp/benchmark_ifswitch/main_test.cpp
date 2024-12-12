#include "benchmark/benchmark.h"

// Funkcja sprawdzająca if
int if_check() {
    return 0;
}

// Funkcja sprawdzająca switch
int switch_check() {
    return 0;
}

// Test wydajności if
static void BM_forIf(benchmark::State& state) {
    for (auto _ : state) {
        // Benchmarkowany kod
        int result = if_check();
    }
}

// Test wydajności switch
static void BM_forSwitch(benchmark::State& state) {
    for (auto _ : state) {
        // Benchmarkowany kod
        int result = switch_check();
    }
}

/////////////////////////////////////////////////////
//uruchomienie benchmarków

BENCHMARK(BM_forIf);
BENCHMARK(BM_forSwitch);

BENCHMARK_MAIN();


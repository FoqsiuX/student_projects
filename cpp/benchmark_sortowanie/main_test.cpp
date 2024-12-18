#include <benchmark/benchmark.h>
#include <algorithm>
#include <vector>
#include <random>
 
std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> vec(size);
    std::mt19937 rng(1234);
    std::uniform_int_distribution<int> dist(0, 100000);
    for (auto& val : vec) {
        val = dist(rng);
    }
    return vec;
}
 
void bubble_sort(std::vector<int>& vec) {
    size_t n = vec.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}
 
static void BM_QuickSort(benchmark::State& state) {
    for (auto _ : state) {
        auto vec = generate_random_vector(state.range(0));
        benchmark::DoNotOptimize(vec);
        std::sort(vec.begin(), vec.end());
    }
}
BENCHMARK(BM_QuickSort)->Arg(10000);
 
static void BM_BubbleSort(benchmark::State& state) {
    for (auto _ : state) {
        auto vec = generate_random_vector(state.range(0));
        benchmark::DoNotOptimize(vec);
        bubble_sort(vec);
    }
}
BENCHMARK(BM_BubbleSort)->Arg(10000);
 
BENCHMARK_MAIN();
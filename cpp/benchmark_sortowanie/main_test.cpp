#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include "benchmark/benchmark.h"

// Globalny wektor z danymi
std::vector<int> globalVec(10000);

// Funkcja wypełniająca wektor losowymi liczbami
void fillVectorWithRandomData(std::vector<int>& vec) {
    std::srand(std::time(0)); // Inicjalizacja generatora liczb losowych
    std::generate(vec.begin(), vec.end(), std::rand); // Wypełnienie wektora losowymi danymi
}


////////////////////////////////////////////////////////

// Funkcja sortująca wektor za pomocą QuickSort
void quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i] < pivot) left.push_back(vec[i]);
        else if (vec[i] > pivot) right.push_back(vec[i]);
    }
    quickSort(left);
    quickSort(right);
    vec.clear();
    vec.insert(vec.end(), left.begin(), left.end());
    vec.push_back(pivot);
    vec.insert(vec.end(), right.begin(), right.end());
}

// Benchmark dla funkcji quickSort
static void BM_quickSort(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> vec_copy = globalVec; // Kopiujemy globalny wektor przed sortowaniem
        quickSort(vec_copy); // Sortujemy wektor
        benchmark::DoNotOptimize(vec_copy); // Zapobiegamy optymalizacji sortowania
    }
}


/////////////////////////////////////////////////////
// Funkcja main do uruchamiania benchmarków
int main(int argc, char** argv) {
    fillVectorWithRandomData(globalVec); // Wypełnienie globalnego wektora przed benchmarkami
    benchmark::Initialize(&argc, argv); // Inicjalizacja Google Benchmark
    // Rejestracja benchmarku
    BENCHMARK(BM_quickSort);
    benchmark::RunSpecifiedBenchmarks(); // Uruchomienie zarejestrowanych benchmarków
}


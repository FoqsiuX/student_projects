#include <iostream>
#include "functions.cpp"

using namespace std;

int main() {
    for (int i = 1; i <= 100; ++i) {
	std::cout << FizzBuzz(i) << std::endl;
    }
    return 0;
}


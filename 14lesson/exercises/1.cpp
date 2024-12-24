#include <iostream>

int fac_recursive(int n) {
    return n > 1 ? n * fac_recursive(n - 1) : 1;
}

int fac_iterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    for (int i = 0; i <= 20; ++i) {
        std::cout << "Factorial of " << i << " (Recursive): " << fac_recursive(i) << std::endl;
        std::cout << "Factorial of " << i << " (Iterative): " << fac_iterative(i) << std::endl;
    }
    return 0;
}
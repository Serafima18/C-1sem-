#include <iostream>
#include <vector>

bool isPrime(int number) {
    if (number <= 1) return false; // 0 и 1 не являются простыми
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false; // Найден делитель
    }
    return true; // Число простое
}

int main() {
    int n;
    std::cout << "Enter the number of prime numbers to find: ";
    std::cin >> n;

    std::vector<int> primes;
    int number = 2; // Первое простое число

    while (primes.size() < n) {
        if (isPrime(number)) {
            primes.push_back(number);
        }
        number++;
    }

    std::cout << "First " << n << " prime numbers: ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) { // Проверяем делимость до корня num
        if (num % i == 0) return false;
    }
    return true; // Если не нашли делителей, это простое число
}

int main() {
    int max;
    std::cout << "Enter number max: ";
    std::cin >> max;

    std::vector<int> primes; // Вектор для хранения простых чисел

    for (int i = 2; i <= max; ++i) {
        if (isPrime(i)) {
            primes.push_back(i); // Если число простое, добавляем его в вектор
        }
    }

    // Выводим все найденные простые числа
    std::cout << "Prime numbers from 1 to " << max << ": ";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

// Функция для проверки, является ли число простым
bool isPrime(int num, const std::vector<int>& primes) {
    // Проверяем делимость на простые числа, не превышающие корень из num
    for (int prime : primes) {
        if (prime * prime > num) break;
        if (num % prime == 0) return false; 
    }
    return true;
}

int main() {
    std::vector<int> primes; // Вектор для хранения простых чисел

    // Перебираем числа от 1 до 100
    for (int i = 2; i <= 100; ++i) {
        if (isPrime(i, primes)) {
            primes.push_back(i);
        }
    }

    // Вывод найденных простых чисел
    std::cout << "Found prime numbers:" << std::endl;
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    // Сравнение с вектором primes (выводим результат)
    std::cout << "The vector contains the following prime numbers from 1 to 100." << std::endl;
    std::cout << "First prime number is " << primes[0] << "." << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

void sieveOfEratosthenes(int n) {
    // Создаем вектор булевских значений (по умолчанию все true)
    std::vector<bool> isPrime(n + 1, true);

    // 0 и 1 не являются простыми числами
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        // Если isPrime[p] не изменился, значит это простое число
        if (isPrime[p]) {
            // Вычёркиваем все кратные p
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Выводим все простые числа
    std::cout << "Prime numbers from 1 to " << n << ":\n";
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            std::cout << p << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int max;
    std::cout << "Enter a number (max): ";
    std::cin >> max; // Ввод числа max от пользователя
    sieveOfEratosthenes(max); // Вызов функции с введенным max
    return 0;
}
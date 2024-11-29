#include <iostream>
#include <vector>

int main() {
    // Вектор для хранения последовательности Фибоначчи
    std::vector<int> fib = {1, 1};

    // Генерируем последовательность до тех пор, пока числа помещаются в int
    while (true) {
        int next = fib[fib.size() - 1] + fib[fib.size() - 2];
        if (next < 0) { // Проверка на переполнение
            break;
        }
        fib.push_back(next);
    }

    // Выводим последовательность
    std::cout << "The Fibonacci sequence: ";
    for (int num : fib) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Выводим последнее число Фибоначчи, которое можно записать в int
    std::cout << "The last Fibonacci number that can be written to an int variable: " 
              << fib.back() << std::endl;

    return 0;
}
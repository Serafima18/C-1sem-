#include <iostream>
#include <stdexcept>
#include <string>

// Функция для вычисления факториала
unsigned long long factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Факториал определен только для неотрицательных чисел.");
    }
    if (n == 0) {
        return 1; // 0! = 1
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Функция для вычисления выражения
unsigned long long evalExpression(const std::string& expr) {
    // Простой парсер для выражения (например, "7 * 8!")
    std::string currentNum;
    unsigned long long result = 1;
    bool multiplication = false;

    for (char c : expr) {
        if (isdigit(c)) {
            currentNum += c; // Собираем число
        } else if (c == '!') {
            if (currentNum.empty()) {
                throw std::invalid_argument("Недопустимое выражение.");
            }
            // Вычисляем факториал
            int num = std::stoi(currentNum);
            result *= factorial(num);
            currentNum.clear(); // Очищаем для следующего числа
        } else if (c == '*') {
            multiplication = true; // Устанавливаем флаг умножения
            if (!currentNum.empty()) {
                result *= std::stoi(currentNum); // Умножаем на текущее число
                currentNum.clear(); // Очищаем для следующего числа
            }
        }
    }
    // Умножаем на последнее собранное число, если есть
    if (!currentNum.empty()) {
        result *= std::stoi(currentNum);
    }

    return result;
}

int main() {
    std::string expression = "7 * 8!"; // Пример выражения
    try {
        unsigned long long result = evalExpression(expression);
        std::cout << "The result of the expression '" << expression << "' = " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a number (from 1 to 9999): ";
    std::cin >> input;

    // Переменная для хранения итогового числа
    int number = 0;

    // Преобразование символов в целое число
    for (char ch : input) {
        number = number * 10 + (ch - '0');
    }

    // Обработка количества сотен, десятков и единиц
    int hundreds = number / 100;
    int tens = (number / 10) % 10;
    int units = number % 10;

    // Формирование и вывод результата
    std::cout << number << " is " 
              << hundreds << " hundred(s), "
              << tens << " ten(s), and "
              << units << " unit(s)." << std::endl;

    return 0;
}
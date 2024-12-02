#include <iostream>
#include <string>   // Подключаем библиотеку для работы со строками
#include <sstream>

int main() {
    std::string input; // Переменная для хранения пользовательского ввода

    // Предлагаем пользователю ввести числа
    std::cout << "Enter several numbers (octal, decimal, or hexadecimal) separated by spaces:";
    std::getline(std::cin, input); // Считываем всю строку ввода

    std::istringstream stream(input);
    std::string number;

    // Обрабатываем каждое число по отдельности
    while (stream >> number) {
        int decimalValue; // Переменная для хранения десятичного значения

        // Определяем формат числа и преобразуем его в десятичный вид
        if (number.substr(0, 2) == "0x") { // Если число шестнадцатеричное
            decimalValue = std::stoi(number, nullptr, 16); // Преобразуем в десятичное
            std::cout << number << " is hex and converts to " << decimalValue << " in decimal." << std::endl;
        } else if (number.substr(0, 1) == "0") { // Если число восьмеричное
            decimalValue = std::stoi(number, nullptr, 8); // Преобразуем в десятичное
            std::cout << number << " is octal and converts to " << decimalValue << " in decimal." << std::endl;
        } else { // Если число десятичное
            decimalValue = std::stoi(number); // Преобразуем в десятичное
            std::cout << number << " is decimal and converts to " << decimalValue << " in decimal." << std::endl;
        }
    }

    return 0;
}
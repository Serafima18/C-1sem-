#include <iostream>
#include <string>
#include <stdexcept> // Для обработки исключений

double safe_stof(const std::string& str) {
    double value = std::stod(str); // Пробуем преобразовать строку в double
    if (value < 0) { // Проверка на отрицательные значения в Кельвинах
        throw std::out_of_range("Temperature cannot be below absolute zero (0 K).");
    }
    return value;
}

int main() {
    std::string input;
    double kelvin;

    std::cout << "Enter the temperature in Kelvin: ";
    std::getline(std::cin, input); // Получаем ввод как строку

    try {
        kelvin = safe_stof(input); // Пробуем преобразовать строку
        double celsius = kelvin - 273.15; // Преобразуем в Цельсии
        std::cout << "Temperature in Celsius: " << celsius << " C" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: Incorrect input. Please enter a valid number." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
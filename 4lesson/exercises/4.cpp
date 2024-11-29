#include <iostream>
#include <string>

double safe_stof(const std::string& str) {
    double value = std::stod(str); // Пробуем преобразовать строку в double
    if (value < -273.15) {
        throw std::out_of_range("Temperature cannot be below absolute zero (-273.15°C).");
    }
    return value;
}

int main() {
    std::string input;
    double celsius;

    std::cout << "Enter the temperature in degrees Celsius: ";
    std::getline(std::cin, input); // Получаем ввод как строку

    try {
        celsius = safe_stof(input); // Пробуем преобразовать строку
        double kelvin = celsius + 273.15;
        std::cout << "Temperature in Kelvin: " << kelvin << " K" << std::endl;
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: Invalid input. Please enter a valid number." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
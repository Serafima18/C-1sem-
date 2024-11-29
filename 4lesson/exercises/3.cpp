#include <iostream>

int main() {
    double celsius;

    std::cout << "Enter the temperature in degrees Celsius: ";
    std::cin >> celsius;

    // Проверка на значение ниже абсолютного нуля
    if (celsius < -273.15) {
        std::cout << "Error: The temperature cannot be below absolute zero (-273.15°C)." << std::endl;
    } else {
        double kelvin = celsius + 273.15;
        std::cout << "Temperature in Kelvin: " << kelvin << " K" << std::endl;
    }

    return 0;
}
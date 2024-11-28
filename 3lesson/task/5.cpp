#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::string input;
    const double epsilon = 1.0 / 10000000.0;

    while (true) {
        std::cout << "Enter two numbers or '|' to exit: ";
        std::getline(std::cin, input);
        if (input == "|") {
            break;
        }
        double num1, num2;
        try {
            size_t pos1 = 0, pos2 = input.find(' ');
            num1 = std::stod(input.substr(pos1, pos2));
            pos1 = pos2 + 1;
            num2 = std::stod(input.substr(pos1));
            if (std::abs(num1 - num2) < epsilon) {
                std::cout << "The numbers are nearly equal: " << std::min(num1, num2) 
                          << ", " << std::max(num1, num2) << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "Input error. Please enter two numbers." << std::endl;
        }
    }
    return 0;
}
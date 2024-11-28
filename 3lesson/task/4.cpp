#include <iostream>
#include <string>

int main() {
    std::string input;
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
            std::cout << "Entered numbers: " << num1 << ", " << num2 << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Input error. Please enter two numbers." << std::endl;
        }
    }
    return 0;
}
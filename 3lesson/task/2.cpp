#include <iostream>
#include <string>

int main() {
    std::string input;
    while (true) {
        std::cout << "Enter two integers or '|' to exit: ";
        std::getline(std::cin, input);
        if (input == "|") {
            break;
        }
        int num1, num2;
        try {
            size_t pos1 = 0, pos2 = input.find(' ');
            num1 = std::stoi(input.substr(pos1, pos2));
            pos1 = pos2 + 1;
            num2 = std::stoi(input.substr(pos1));
            int min_value = std::min(num1, num2);
            int max_value = std::max(num1, num2);
            std::cout << "The smallest of the two values is: " << min_value 
                      << ", the larger value is: " << max_value << std::endl;
        } catch (const std::invalid_argument& e) {
            std::cout << "Input error. Please enter two integers." << std::endl;
        }
    }
    return 0;
}
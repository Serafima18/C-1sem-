#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

double convert_length(const std::string &value_with_unit) {
    // List of acceptable units
    std::map<std::string, double> units = {
        {"cm", 0.01},
        {"m", 1.0},
        {"in", 0.0254},
        {"ft", 0.3048}
    };

    // Check input format
    if (value_with_unit.length() < 3) {
        throw std::invalid_argument("Invalid input. Please enter a value in the format 'numberUnit' (e.g., 3.33m).");
    }

    std::string number_str;
    std::string unit_str;
    size_t i = 0;

    // Split the number and unit
    while (i < value_with_unit.length() && (isdigit(value_with_unit[i]) || value_with_unit[i] == '.' || (value_with_unit[i] == '-' && number_str.empty()))) {
        number_str += value_with_unit[i];
        i++;
    }

    while (i < value_with_unit.length()) {
        unit_str += value_with_unit[i];
        i++;
    }

    if (number_str.empty() || units.find(unit_str) == units.end()) {
        throw std::invalid_argument("Invalid input. Please ensure the input is correct and the unit is acceptable.");
    }

    // Convert number
    double value = std::stod(number_str);

    // Convert to meters
    double value_in_meters = value * units[unit_str];
    return value_in_meters;
}

int main() {
    try {
        std::string user_input;
        std::cout << "Enter a length value (e.g., 3.33m): ";
        std::cin >> user_input;
        
        double result = convert_length(user_input);
        std::cout << "The length in meters is: " << result << " m." << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
    return 0;
}
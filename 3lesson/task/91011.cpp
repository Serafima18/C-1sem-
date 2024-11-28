#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    std::vector<double> values;
    double input;
    double sum = 0.0;
    double min_value = std::numeric_limits<double>::max();
    double max_value = std::numeric_limits<double>::lowest();

    std::cout << "Enter values (input '|' to finish):" << std::endl;

    while (std::cin >> input) {
        values.push_back(input);
        sum += input;

        if (input < min_value) {
            min_value = input;
        }
        if (input > max_value) {
            max_value = input;
        }
    }

    // Clear the input stream for the next input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (values.size() < 2) {
        std::cout << "Not enough values entered." << std::endl;
        return 1;
    }

    sum -= (min_value + max_value); // Remove min and max from total sum
    int count = values.size() - 2; // Decrease by two for min and max

    std::cout << "Minimum value: " << min_value << std::endl;
    std::cout << "Maximum value: " << max_value << std::endl;
    std::cout << "Count of values (excluding min and max): " << count << std::endl;
    std::cout << "Sum of values (excluding min and max): " << sum << std::endl;

    std::cout << "Values entered (in meters):" << std::endl;
    for (const auto &value : values) {
        std::cout << value << " meters" << std::endl;
    }

    std::sort(values.begin(), values.end());

    std::cout << "Sorted values (in ascending order):" << std::endl;
    for (const auto &value : values) {
        std::cout << value << " meters" << std::endl;
    }

    return 0;
}
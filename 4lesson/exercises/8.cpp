#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<int> numbers;
    int number;
    
    std::cout << "Please enter some numbers (to stop typing, press the |<| key):" << std::endl;

    // Считываем числа, пока не будет введен нечисловой ввод
    while (std::cin >> number) {
        numbers.push_back(number);
    }

    // Очищаем поток ввода для дальнейшего использования
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Please enter the number of numbers you want to sum (starting from the first one):" << std::endl;
    
    int count;
    std::cin >> count;

    // Проверяем, достаточно ли введено чисел
    if (count > numbers.size()) {
        std::cout << "Error: The requested number of numbers is more than entered." << std::endl;
    } else {
        int sum = 0;
        for (int i = 0; i < count; ++i) {
            sum += numbers[i];
        }
        std::cout << "The sum of the first " << count << " numbers: ";
        for (int i = 0; i < count; ++i) {
            std::cout << numbers[i];
            if (i < count - 1) std::cout << ", ";
        }
        std::cout << " equal to " << sum << "." << std::endl;
    }

    return 0;
}
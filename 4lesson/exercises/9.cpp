#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<double> numbers;
    double number;

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
        std::cout << "Error: The requested number of numbers is more than what was entered." << std::endl;
    } else {
        double sum = 0.0;
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

    // Создаём вектор разностей между соседними величинами
    std::vector<double> differences;
    for (size_t i = 1; i < numbers.size(); ++i) {
        differences.push_back(numbers[i] - numbers[i - 1]);
    }

    // Выводим вектор разностей
    std::cout << "The vector of differences between neighboring quantities: ";
    for (size_t i = 0; i < differences.size(); ++i) {
        std::cout << differences[i];
        if (i < differences.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Подключение для std::find

int main() {
    // Создаем вектор, хранящий строковые представления чисел от 0 до 9
    std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", 
                                         "five", "six", "seven", "eight", "nine"};
    
    // Переменные для ввода
    int num;
    std::string str;

    // Ввод числа
    std::cout << "Enter a number between 0 and 9: ";
    std::cin >> num;

    if (num >= 0 && num <= 9) {
        // Вывод строкового представления числа
        std::cout << "The number in words is: " << numbers[num] << std::endl;
    } else {
        std::cout << "Invalid number!" << std::endl;
    }

    // Ввод строки
    std::cout << "Enter a number in words (from zero to nine): ";
    std::cin >> str;

    // Преобразование строкового представления в число
    auto it = std::find(numbers.begin(), numbers.end(), str);
    if (it != numbers.end()) {
        int index = std::distance(numbers.begin(), it);
        // Вывод числа
        std::cout << "The number is: " << index << std::endl;
    } else {
        std::cout << "Invalid input!" << std::endl;
    }

    return 0;
}
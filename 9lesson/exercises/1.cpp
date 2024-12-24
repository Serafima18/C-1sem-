#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    // Открываем файл для чтения
    std::ifstream inputFile("numbers.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl; // Ошибка открытия файла
        return 1;
    }

    // Переменная для хранения суммы
    int sum = 0;
    // Переменная для чтения каждого числа
    int number;

    // Считываем числа из файла
    while (inputFile >> number) {
        sum += number; // Добавляем число к сумме
    }

    // Закрываем файл
    inputFile.close();

    // Выводим результат на экран
    std::cout << "The sum of all integers in the file is: " << sum << std::endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream inputFile("numbers.txt"); // Укажите имя файла
    if (!inputFile) {
        std::cerr << "File opening error!" << std::endl;
        return 1;
    }

    std::map<int, int> numberCount;
    std::string line;

    // Считываем все числа из файла
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int number;
        while (iss >> number) {
            numberCount[number]++;
        }
    }

    inputFile.close();

    // Сортировка чисел
    std::vector<int> uniqueNumbers;
    for (const auto& pair : numberCount) {
        uniqueNumbers.push_back(pair.first);
    }
    std::sort(uniqueNumbers.begin(), uniqueNumbers.end());

    // Вывод результата
    for (const int number : uniqueNumbers) {
        if (numberCount[number] > 1) {
            std::cout << number << " " << numberCount[number] - 1 << std::endl;
        } else {
            std::cout << number << std::endl;
        }
    }

    return 0;
}
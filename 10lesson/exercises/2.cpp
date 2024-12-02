#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool isVowel(char ch) {
    // Проверяем, является ли буква гласной
    ch = tolower(ch); // Приводим букву к нижнему регистру
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void removeVowelsFromFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile); // Открываем входной файл
    std::ofstream outFile(outputFile); // Открываем выходной файл

    if (!inFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl; // Сообщение об ошибке
        return;
    }
    
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl; // Сообщение об ошибке
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        // Удаляем гласные из строки
        for (char ch : line) {
            if (!isVowel(ch)) {
                outFile << ch; // Записываем символ в выходной файл, если это не гласная
            }
        }
        outFile << std::endl; // Переход на новую строку в выходном файле
    }

    inFile.close(); // Закрываем входной файл
    outFile.close(); // Закрываем выходной файл
}

int main() {
    const std::string inputFile = "input.txt"; // Имя входного файла
    const std::string outputFile = "output.txt"; // Имя выходного файла

    removeVowelsFromFile(inputFile, outputFile); // Удаляем гласные буквы

    std::cout << "Vowels have been removed. Check the output file." << std::endl; // Сообщение пользователю

    return 0;
}
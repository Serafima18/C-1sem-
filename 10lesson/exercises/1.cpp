#include <iostream>
#include <fstream>
#include <cctype> // Для функции tolower
#include <string>

int main() {
    std::string inputFileName, outputFileName;
    
    // Запрашиваем у пользователя имена файлов
    std::cout << "Enter the input file name: ";
    std::cin >> inputFileName;
    
    std::cout << "Enter the output file name: ";
    std::cin >> outputFileName;
    
    // Открываем входной файл для чтения
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << inputFileName << std::endl;
        return 1; // Завершаем программу с ошибкой
    }
    
    // Открываем выходной файл для записи
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "Error creating file: " << outputFileName << std::endl;
        return 1; // Завершаем программу с ошибкой
    }
    
    std::string line;
    // Читаем файл построчно
    while (std::getline(inputFile, line)) {
        // Переводим всю строку в нижний регистр
        for (char &c : line) {
            c = std::tolower(c);
        }
        // Записываем обработанную строку в выходной файл
        outputFile << line << std::endl;
    }
    
    // Закрываем файлы
    inputFile.close();
    outputFile.close();
    
    return 0; // Успешное завершение программы
}
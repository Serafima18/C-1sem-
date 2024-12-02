#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    // Открываем файл для чтения
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "The file cannot be opened for reading." << std::endl;
        return 1;
    }
    
    // Считываем содержимое файла в строку
    std::string content;
    std::getline(inputFile, content);
    
    // Закрываем файл
    inputFile.close();
    
    // Изменяем порядок следования символов
    std::reverse(content.begin(), content.end());
    
    // Открываем файл для записи (перезаписать исходный файл)
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "The file cannot be opened for writing." << std::endl;
        return 1;
    }
    
    // Записываем изменённое содержимое в файл
    outputFile << content;
    
    // Закрываем файл
    outputFile.close();
    
    std::cout << "The order of the characters has been changed and written to the file output.txt ." << std::endl;
    return 0;
}
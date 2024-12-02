#include <iostream>
#include <fstream>
#include <cctype> // для функции isdigit, isalpha и т.д.

void countCharacterCategories(const std::string &inputFile, const std::string &outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open()) {
        std::cerr << "Error opening the file for reading." << std::endl;
        return;
    }
    
    if (!outFile.is_open()) {
        std::cerr << "Error opening the file for writing." << std::endl;
        return;
    }

    int letters = 0;
    int digits = 0;
    int spaces = 0;
    int others = 0;
    char ch;

    while (inFile.get(ch)) {
        if (std::isalpha(ch)) {
            letters++;
        } else if (std::isdigit(ch)) {
            digits++;
        } else if (std::isspace(ch)) {
            spaces++;
        } else {
            others++;
        }
    }

    outFile << "Number of letters: " << letters << std::endl;
    outFile << "Number of digits: " << digits << std::endl;
    outFile << "Number of spaces: " << spaces << std::endl;
    outFile << "The number of remaining characters: " << others << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt";  // Имя входного файла
    std::string outputFile = "output.txt"; // Имя выходного файла

    countCharacterCategories(inputFile, outputFile);

    return 0;
}
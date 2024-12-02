#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

void reverseWordsInFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "The file could not be opened." << std::endl;
        return;
    }

    std::string line;
    while (getline(inFile, line)) {
        std::istringstream iss(line);
        std::vector<std::string> words;

        // Считываем слова из строки
        std::string word;
        while (iss >> word) {
            words.push_back(word);
        }

        // Меняем порядок слов
        std::reverse(words.begin(), words.end());

        // Записываем изменённую строку в файл
        for (size_t i = 0; i < words.size(); ++i) {
            outFile << words[i];
            if (i != words.size() - 1) {
                outFile << " "; // добавляем пробел между словами
            }
        }
        outFile << std::endl; // переводим строку
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt"; // имя входного файла
    std::string outputFile = "output.txt"; // имя выходного файла

    reverseWordsInFile(inputFile, outputFile);

    std::cout << "The word order has been changed and saved in " << outputFile << std::endl;
    return 0;
}
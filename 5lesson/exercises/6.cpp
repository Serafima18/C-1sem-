#include <iostream>
#include <sstream>
#include <vector>
#include <string>

bool isNoun(const std::string &word) {
    return (word == "birds" || word == "fish" || word == "C++");
}

bool isVerb(const std::string &word) {
    return (word == "rules" || word == "fly" || word == "swim");
}

bool isConjunction(const std::string &word) {
    return (word == "and" || word == "or" || word == "but");
}

bool isValidSentence(const std::string &sentence) {
    std::istringstream stream(sentence);
    std::string word;
    bool hasNoun = false;
    bool hasVerb = false;
    bool expectConjunction = false;
    
    while (stream >> word) {
        // Remove trailing period if present
        if (word.back() == '.') {
            word.pop_back();
        }

        if (isNoun(word)) {
            if (expectConjunction) return false; // Неожиданный существительное
            hasNoun = true;
        } else if (isVerb(word)) {
            if (!hasNoun) return false; // Глагол без существительного
            hasVerb = true;
            expectConjunction = true; // Ожидаем союз или конец
        } else if (isConjunction(word)) {
            if (!hasVerb || !hasNoun) return false; // Союз без глагола и существительного
            hasNoun = false; // Сбросить ожидания перед союзом
            hasVerb = false; // Сбросить ожидания перед союзом
        } else {
            return false; // Неизвестное слово
        }
    }
    
    // Проверка на конец предложения
    return hasNoun && hasVerb && !expectConjunction; // Существительное и глагол должны быть в конце
}

int main() {
    std::string line;

    while (std::getline(std::cin, line)) {
        // Удаление пробелов в начале и конце
        line.erase(0, line.find_first_not_of(" "));
        line.erase(line.find_last_not_of(" ") + 1);
        
        if (line.empty() || line.back() != '.') {
            std::cout << "No" << std::endl;
            continue;
        }

        // Проверка предложения
        if (isValidSentence(line)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
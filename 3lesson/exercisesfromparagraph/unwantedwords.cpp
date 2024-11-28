#include <iostream>
#include <string>
#include <vector>

int main() {
    // Список нежелательных слов
    std::vector<std::string> dislikedWords = {"Broccoli", "Carrot", "Spinach"};
    
    std::string word;
    
    std::cout << "Enter world (to exit enter: 'exit'):\n";
    
    while (std::cin >> word) {
        // Проверяем, есть ли слово в списке нежелательных
        bool found = false;
        for (const auto& disliked : dislikedWords) {
            if (word == disliked) {
                std::cout << "BLEEP ";
                found = true;
                break;
            }
        }
        // Если слово не нежелательное, выводим его
        if (!found) {
            std::cout << word << " ";
        }

        // Условие выхода из цикла
        if (word == "exit") {
            break;
        }
    }

    std::cout << std::endl;
    return 0;
}
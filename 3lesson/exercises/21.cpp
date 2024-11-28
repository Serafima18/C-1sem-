#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <limits> // Для std::numeric_limits

using namespace std;

int main() {
    unordered_map<int, vector<string>> scoreNameMap; // Мапа для хранения баллов и соответствующих имен
    unordered_set<string> uniqueNames; // Множество для проверки уникальности имен

    string name;
    int score;

    // Ввод имен и баллов
    while (true) {
        cout << "Enter name and score (or 'No more' to finish): ";
        cin >> name;

        // Прекращаем ввод, если введено 'No'
        if (name == "No more") {
            // Игнорируем остаток строки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            break; 
        }
        
        cin >> score;

        // Проверяем уникальность имени
        if (uniqueNames.find(name) != uniqueNames.end()) {
            cout << "Error: name '" << name << "' already exists." << endl;
            continue; // Возвращаемся к началу цикла для нового ввода
        }

        // Добавляем имя в мапу по баллу
        scoreNameMap[score].push_back(name);
        uniqueNames.insert(name); // Сохраняем имя для проверки уникальности
    }

    // Вывод результатов
    cout << "Scores and corresponding Names:" << endl;
    for (const auto& entry : scoreNameMap) {
        cout << "Score: " << entry.first << " => Names: ";
        for (const auto& nm : entry.second) {
            cout << nm << " ";
        }
        cout << endl;
    }

    return 0;
} 
// Выдает ошибку
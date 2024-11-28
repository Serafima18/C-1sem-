#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    vector<string> names; // Вектор для хранения имен
    vector<int> scores; // Вектор для хранения баллов
    unordered_map<string, int> nameScoreMap; // Словарь для хранения соответствия имя - балл

    string name;
    int score;

    // Ввод пар имени и значения
    while (true) {
        cout << "Enter name and score (or 'No more' to finish): ";
        if (cin >> name && name == "No") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break; // Прекратить ввод
        }
        
        cin >> score;
        if (nameScoreMap.find(name) != nameScoreMap.end()) {
            cout << "Error: name '" << name << "' already exists." << endl;
            continue; // Возвращаемся к началу цикла
        }

        names.push_back(name); // Добавляем имя в вектор
        scores.push_back(score); // Добавляем балл в вектор
        nameScoreMap[name] = score; // Сохраняем соответствие в словаре
    }

    // Запрос имени и вывод соответствующего балла
    cout << "Enter a name to find the score: ";
    cin >> name;

    if (nameScoreMap.find(name) != nameScoreMap.end()) {
        cout << "Score for " << name << ": " << nameScoreMap[name] << endl;
    } else {
        cout << "name not found" << endl;
    }

    return 0;
}
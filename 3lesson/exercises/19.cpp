#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <limits>

using namespace std;

int main() {
    vector<string> names; // Вектор для хранения имен
    vector<int> scores; // Вектор для хранения баллов
    unordered_set<string> uniqueNames; // Множество для проверки уникальности имен

    string name;
    int score;

    while (true) {
        cout << "Enter name and score (or 'No more' to finish): ";
        if (cin >> name && name == "No") {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break; // Прекратить ввод, если введено 'No more'
        }
        
        cin >> score;

        // Проверяем уникальность имени
        if (uniqueNames.find(name) != uniqueNames.end()) {
            cout << "Error: name '" << name << "' already exists." << endl;
            continue; // Возвращаемся к началу цикла для нового ввода
        }

        names.push_back(name); // Добавляем имя в вектор
        scores.push_back(score); // Добавляем балл в вектор
        uniqueNames.insert(name); // Добавляем имя в множество уникальных имен
    }

    // Выводим все пары (имя, балл)
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "(" << names[i] << ", " << scores[i] << ")" << endl;
    }

    return 0;
}
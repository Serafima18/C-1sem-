#include <iostream>
#include <string>
#include <vector>
#include <sstream> // Для std::istringstream

using namespace std;

// Функция, которая разбивает строку на подстроки по пробелам
vector<string> split(const string& s) {
    vector<string> result;
    istringstream stream(s); // Создаем поток из строки
    string word;

    // Извлекаем слова из потока, разделяя их пробелами
    while (stream >> word) {
        result.push_back(word);
    }

    return result; // Возвращаем вектор подстрок
}

int main() {
    string input;
    cout << "Enter the line: ";
    getline(cin, input); // Считываем строку с пробелами

    vector<string> words = split(input); // Разбиваем строку на подстроки

    cout << "Substrings:" << endl;
    for (const string& word : words) {
        cout << word << endl; // Выводим каждую подстроку
    }

    return 0;
}
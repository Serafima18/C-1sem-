#include <iostream>
#include <string>
#include <cctype>  // Для функций ispunct

using namespace std;

int main() {
    string input; // Входная строка
    cout << "Enter the line: ";
    getline(cin, input); // Считываем строку

    string output; // Выходная строка
    for (char ch : input) {
        if (!ispunct(ch)) { // Если символ не является знаком пунктуации
            output += ch; // Добавляем его к выходной строке
        }
    }

    // Удаляем лишние пробелы
    size_t pos = 0;
    while ((pos = output.find("  ", pos)) != string::npos) {
        output.replace(pos, 2, " "); // Заменяем дублирующиеся пробелы на один пробел
    }

    // Удаляем пробелы в начале и в конце строки
    if (!output.empty() && output.front() == ' ') {
        output.erase(output.begin());
    }
    if (!output.empty() && output.back() == ' ') {
        output.pop_back();
    }

    cout << "Result: " << output << endl; // Выводим результат
    return 0;
}
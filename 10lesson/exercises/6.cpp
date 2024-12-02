#include <iostream>
#include <string>
#include <cctype>  // Для функций ispunct

using namespace std;

string replaceShortcuts(const string& input) {
    string output = input;

    // Заменяем сокращения
    size_t pos = output.find("don't");
    while (pos != string::npos) {
        output.replace(pos, 5, "do not");
        pos = output.find("don't", pos + 6);
    }

    pos = output.find("can't");
    while (pos != string::npos) {
        output.replace(pos, 5, "cannot");
        pos = output.find("can't", pos + 7);
    }

    return output;
}

int main() {
    string input; // Входная строка
    cout << "Enter the line: ";
    getline(cin, input); // Считываем строку

    // Заменяем сокращения
    string modifiedInput = replaceShortcuts(input);

    string output; // Выходная строка
    for (char ch : modifiedInput) {
        if (!ispunct(ch) || ch == '-') { // Если символ не является знаком пунктуации, или это дефис
            output += ch; // Добавляем его к выходной строке
        }
    }

    // Переводим все символы в нижний регистр
    for (char& ch : output) {
        ch = tolower(ch);
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
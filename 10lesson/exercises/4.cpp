#include <iostream>
#include <string>
#include <cctype> // Для функций isalpha, isdigit и т.д.

using namespace std;

void classifyCharacter(char ch) {
    if (isalpha(ch)) {
        cout << ch << ": letter character" << endl;
    }
    if (isdigit(ch)) {
        cout << ch << ": digital symbol" << endl;
    }
    if (isalnum(ch)) {
        cout << ch << ": alphanumeric character" << endl;
    }
    if (isspace(ch)) {
        cout << ch << ": space character" << endl;
    }
    if (ispunct(ch)) {
        cout << ch << ": punctuation symbol" << endl;
    }
    // Добавьте другие категории, если нужно
}

int main() {
    string input;

    cout << "Enter the line: ";
    getline(cin, input);

    for (char ch : input) {
        classifyCharacter(ch);
    }

    return 0;
}
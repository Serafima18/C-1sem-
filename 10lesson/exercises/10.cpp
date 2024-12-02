#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& s, const string& w) {
    vector<string> result;
    string::size_type start = 0, end;

    // Пройти по строке s
    while (start < s.length()) {
        // Найти следующий разделитель
        end = s.find_first_of(w, start);
        
        // Если не найден разделитель, добавляем остальную часть строки
        if (end == string::npos) {
            result.push_back(s.substr(start));
            break;
        }

        // Добавляем подстроку в вектор
        if (end > start) {
            result.push_back(s.substr(start, end - start));
        }

        // Переход к следующей подстроке
        start = end + 1;
    }

    return result;
}

int main() {
    string input;
    string delimiters;

    cout << "Enter the line: ";
    getline(cin, input);
    
    cout << "Enter the delimiter characters: ";
    getline(cin, delimiters);

    vector<string> words = split(input, delimiters);

    cout << "Substrings:" << endl;
    for (const string& word : words) {
        cout << word << endl;
    }

    return 0;
}
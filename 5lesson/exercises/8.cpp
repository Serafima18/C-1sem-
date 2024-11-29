#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

// Генерация уникальной четырёхбуквенной строки
vector<char> generateLetters() {
    set<char> letters;
    vector<char> number;

    while (letters.size() < 4) {
        char letter = 'A' + rand() % 26; // Генерация буквы от 'A' до 'Z'
        letters.insert(letter);
    }
    
    // Преобразуем набор в вектор
    number.assign(letters.begin(), letters.end());
    return number;
}

// Проверка правильности ввода пользователя
bool isValidInput(const string& input) {
    if (input.length() != 4) return false; // Должно быть ровно 4 символа
    set<char> letterSet;

    for (char c : input) {
        if (c < 'A' || c > 'Z') return false; // Проверка на диапазон букв
        if (letterSet.find(c) != letterSet.end()) return false; // Проверка на уникальность
        letterSet.insert(c);
    }
    return true;
}

// Подсчет быков и коров
pair<int, int> getBullsAndCows(const vector<char>& secret, const vector<char>& guess) {
    int bulls = 0, cows = 0;
    vector<bool> secretUsed(4, false), guessUsed(4, false);

    // Считаем быков
    for (int i = 0; i < 4; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
            secretUsed[i] = true;
            guessUsed[i] = true;
        }
    }

    // Считаем коров
    for (int i = 0; i < 4; ++i) {
        if (!guessUsed[i]) {
            for (int j = 0; j < 4; ++j) {
                if (!secretUsed[j] && guess[i] == secret[j]) {
                    cows++;
                    secretUsed[j] = true; // Отметить букву как использованную
                    break;
                }
            }
        }
    }

    return {bulls, cows};
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<char> secret = generateLetters(); // Генерация секретного слова

    cout << "Welcome to the Bulls and Cows game with letters!" << endl;

    string userGuess;
    int attempts = 0;

    while (true) {
        cout << "Enter your guess (a four-letter string without duplicate letters): ";
        cin >> userGuess;

        // Проверка валидности ввода
        if (!isValidInput(userGuess)) {
            cout << "Incorrect input. Please try again." << endl;
            continue; // Повторить ввод
        }

        // Подсчет "быков" и "коров"
        vector<char> guess(userGuess.begin(), userGuess.end());
        auto [bulls, cows] = getBullsAndCows(secret, guess);
        attempts++;

        cout << "Bulls: " << bulls << ", Cows: " << cows << endl;

        // Проверка условия победы
        if (bulls == 4) {
            cout << "Congratulations! You've guessed the secret word: " << string(secret.begin(), secret.end()) << " in " << attempts << " attempts!" << endl;
            break;
        }
    }

    return 0;
}
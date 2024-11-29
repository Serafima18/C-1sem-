#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

// Генерирует уникальное четырехзначное число
vector<int> generateNumber() {
    set<int> digits;
    vector<int> number;

    while (digits.size() < 4) {
        int digit = rand() % 10;
        if (digits.find(digit) == digits.end()) {
            digits.insert(digit);
            number.push_back(digit);
        }
    }
    
    return number;
}

// Подсчитывает быков и коров
pair<int, int> getBullsAndCows(const vector<int>& secret, const vector<int>& guess) {
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
                    secretUsed[j] = true;
                    break;
                }
            }
        }
    }

    return make_pair(bulls, cows);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
    int seed;

    cout << "Welcome to the Bulls and Cows game!" << endl;
    cout << "Please enter a seed number for randomness: ";
    cin >> seed;
    srand(seed); // Установка начального значения генератора случайных чисел

    char playAgain;

    do {
        vector<int> secret = generateNumber();
        int attempts = 0;
        bool isGuessed = false;

        while (!isGuessed) {
            attempts++;

            cout << "Enter your guess (a four-digit number without duplicate digits): ";
            string input;
            cin >> input;

            if (input.length() != 4 || input.find_first_not_of("0123456789") != string::npos) {
                cout << "Incorrect input. Please try again." << endl;
                continue;
            }

            vector<int> guess;
            set<char> digits;

            for (char ch : input) {
                if (digits.find(ch) != digits.end()) {
                    cout << "The numbers should not be repeated. Try again." << endl;
                    guess.clear();
                    break;
                }
                guess.push_back(ch - '0');
                digits.insert(ch);
            }

            if (guess.size() != 4) continue;

            auto [bulls, cows] = getBullsAndCows(secret, guess);

            cout << bulls << " bulls and " << cows << " cows." << endl;

            if (bulls == 4) {
                isGuessed = true;
                cout << "Congratulations! You guessed the number for " << attempts << " attempts!" << endl;
            }
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
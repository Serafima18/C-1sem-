#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));
    
    vector<string> choices = {"rock", "paper", "scissors"};
    int machineChoiceIndex = 0;

    // Бесконечный цикл для игры
    while (true) {
        // Показать варианты
        cout << "Enter 'rock', 'paper', or 'scissors'. To exit, type 'exit': ";
        string userChoice;
        cin >> userChoice;

        if (userChoice == "exit") {
            break;
        }

        // Генерация случайного выбора машины
        machineChoiceIndex = rand() % choices.size();
        string machineChoice = choices[machineChoiceIndex];

        cout << "Machine chose: " << machineChoice << endl;

        // Определение результата игры
        if (userChoice == machineChoice) {
            cout << "It's a tie!" << endl;
        } else {
            switch (hash<string>{}(userChoice) % 3) {
                case 0: // "камень"
                    if (machineChoice == "scissors") {
                        cout << "You win!" << endl;
                    } else {
                        cout << "You lose!" << endl;
                    }
                    break;
                case 1: // "бумага"
                    if (machineChoice == "rock") {
                        cout << "You win!" << endl;
                    } else {
                        cout << "You lose!" << endl;
                    }
                    break;
                case 2: // "ножницы"
                    if (machineChoice == "paper") {
                        cout << "You win!" << endl;
                    } else {
                        cout << "You lose!" << endl;
                    }
                    break;
                default:
                    cout << "Invalid input. Please try again." << endl;
            }
        }

        cout << "Game over. Thank you for playing!" << endl;
    }

    return 0;
}
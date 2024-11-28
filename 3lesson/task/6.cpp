#include <iostream>
#include <limits>

using namespace std;

int main() {
    double value;
    double minValue = numeric_limits<double>::max();
    double maxValue = numeric_limits<double>::min();

    while (true) {
        cout << "Enter a number (type 'exit' to quit): ";
        
        // Проверяем, введено ли значение
        if (!(cin >> value)) {
            string input;
            cin.clear(); // Очистка флага ошибки
            cin >> input; // Считывание строки для проверки выхода
            if (input == "exit") break; // Выход из цикла
            cout << "Invalid input. Please enter a valid number.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем остаток строки
            continue;
        }

        // Вывод введенного значения
        cout << "You entered: " << value << endl;

        // Сравнение с текущими min и max
        if (value < minValue) {
            minValue = value;
            cout << "This is the smallest among the previously entered values." << endl;
        }
        if (value > maxValue) {
            maxValue = value;
            cout << "This is the largest among the previously entered values." << endl;
        }
    }
    
    return 0;
}
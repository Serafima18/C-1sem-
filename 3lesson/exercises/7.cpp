#include <iostream>
#include <string>

using namespace std;

double convertToNumber(const string& str) {
    double number;
    try {
        number = stod(str); // Преобразует строку в число
    } catch (const invalid_argument&) {
        cerr << "Invalid number format: " << str << endl;
        exit(EXIT_FAILURE);
    } catch (const out_of_range&) {
        cerr << "Number out of range: " << str << endl;
        exit(EXIT_FAILURE);
    }
    return number;
}

int main() {
    string input1, input2;
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> input1;
    num1 = convertToNumber(input1); // Конвертируем строку в число

    cout << "Enter second number: ";
    cin >> input2;
    num2 = convertToNumber(input2); // Конвертируем строку в число

    cout << "Enter operation (+, -, *, /, %): ";
    cin >> operation;

    switch (operation) {
        case '+':
            cout << "Sum " << num1 << " and " << num2 << " is " << (num1 + num2) << endl;
            break;
        case '-':
            cout << "Difference " << num1 << " and " << num2 << " is " << (num1 - num2) << endl;
            break;
        case '*':
            cout << "Product " << num1 << " and " << num2 << " is " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Division " << num1 << " by " << num2 << " is " << (num1 / num2) << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        case '%':
            if (static_cast<int>(num2) != 0) {
                cout << "Remainder of " << num1 << " divided by " << num2 << " is " 
                     << (static_cast<int>(num1) % static_cast<int>(num2)) << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        default:
            cout << "Invalid operation" << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
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
                cout << "Remainder of " << num1 << " divided by " << num2 << " is " << (static_cast<int>(num1) % static_cast<int>(num2)) << endl;
            } else {
                cout << "Error: Division by zero" << endl;
            }
            break;
        default:
            cout << "Invalid operation" << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

// Функция для проверки, является ли число простым
bool is_prime(int number) 
{
    if (number <= 1) 
    {
        return false; // Числа меньше или равные 1 не являются простыми
    }
    for (int i = 2; i * i <= number; ++i) 
    {
        if (number % i == 0) 
        {
            return false; // Если число делится на i, оно не простое
        }
    }
    return true; // Если не нашлось делителей, число простое
}

int main() {
    cout << "enter an integer: ";
    int num;
    cin >> num;

    // Проверка, является ли число простым
    if (is_prime(num)) {
        cout << num << " is a prime number.\n";
    } else {
        cout << num << " is not a prime number.\n";
    }

    return 0;
}
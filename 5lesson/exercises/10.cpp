#include <iostream>
using namespace std;

// Функция для вычисления факториала
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Функция для вычисления перестановок
long long permutations(int a, int b) {
    return factorial(a) / factorial(a - b);
}

// Функция для вычисления сочетаний
long long combinations(int a, int b) {
    return permutations(a, b) / factorial(b);
}

int main() {
    int a, b;
    char choice;
    
    // Запрос у пользователя двух чисел
    cout << "Enter two numbers (n and r): ";
    cin >> a >> b;
    
    // Проверка на корректность ввода
    if (a < 0 || b < 0 || b > a) {
        cout << "Invalid input. Make sure n >= 0 and r >= 0 and r <= n." << endl;
        return 1; // Завершение программы с ошибкой
    }
    
    // Запрос у пользователя, что он хочет вычислить
    cout << "Do you want to calculate permutations (P) or combinations (C)? ";
    cin >> choice;
    
    if (choice == 'P' || choice == 'p') {
        // Вычисление и вывод перестановок
        cout << "Permutations (P(" << a << ", " << b << ")) = " << permutations(a, b) << endl;
    } else if (choice == 'C' || choice == 'c') {
        // Вычисление и вывод сочетаний
        cout << "Combinations (C(" << a << ", " << b << ")) = " << combinations(a, b) << endl;
    } else {
        cout << "Invalid choice. Please choose either 'P' for permutations or 'C' for combinations." << endl;
    }

    return 0;
}
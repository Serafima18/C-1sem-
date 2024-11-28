#include <iostream>
using namespace std;

// Функция для вычисления квадрата числа с помощью повторного сложения
int square(int x) {
    int result = 0;
    for (int i = 0; i < x; ++i) {
        result += x; // Добавляем x к результату x раз
    }
    return result;
}

// Функция для печати квадрата числа
void print_square(int v) {
    cout << '\t' << v << '\t' << square(v) << '\n';
}

int main() {
    for (int i = 0; i < 100; ++i) {
        print_square(i);
    }
    return 0;
}
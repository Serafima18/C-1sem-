#include <iostream>
#include <cmath> // Для удобной работы с математическими функциями
using namespace std;

int main() {
    double a, b, c; // Объявление переменных для коэффициентов
    cout << "Enter the values a, b and c: "; // Запрос значений у пользователя
    cin >> a >> b >> c; // Ввод значений

    // Проверка на нулевое значение 'a', так как это должно быть квадратное уравнение
    if (a == 0) {
        cout << "The coefficient 'a' cannot be zero." << endl; // Ошибка
        return 1; // Завершение программы с кодом ошибки
    }

    double discriminant = b * b - 4 * a * c; // Вычисление дискриминанта

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a); // Первое решение
        double x2 = (-b - sqrt(discriminant)) / (2 * a); // Второе решение
        cout << "The equation has two solutions: x1 = " << x1 << ", x2 = " << x2 << endl; // Вывод решений
    } else if (discriminant == 0) {
        double x = -b / (2 * a); // Единственное решение
        cout << "The equation has one solution: x = " << x << endl; // Вывод решения
    } else {
        cout << "The equation has no valid solutions." << endl; // Нет решений
    }

    return 0; // Успешное завершение программы
}
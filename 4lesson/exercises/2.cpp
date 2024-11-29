#include <iostream>
using namespace std;

// Функция для преобразования шкалы Цельсия в шкалу Кельвина
double ctok(double c) { //изменена переменная с int на double, был некоретно записано преобразование ctok
    return c + 273.15; // возвращаем температуру в Кельвинах
}

int main() {
    double c; // объявляем переменную для ввода
    cout << "Enter the temperature in degrees Celsius: "; // выводим сообщение для пользователя
    cin >> c; // вводим температуру в переменную
    double k = ctok(c); // преобразуем температуру
    cout << "Temperature in Kelvin: " << k << endl; // выводим температуру на печать
    return 0; // завершаем программу
}
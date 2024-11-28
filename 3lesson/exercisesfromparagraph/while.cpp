#include <iostream>

using namespace std;

int main() 
{
    // Переменная для хранения символа
    char c = 'a';

    // Вывод заголовка таблицы
    cout << "Symbol\tNumber" << endl;

    // Используем цикл while для вывода символов и их кодов
    while (c <= 'z') 
    {
        cout << c << "\t" << static_cast<int>(c) << endl;
        c++; // Переход к следующему символу
    }

    return 0;
}
#include <iostream>

using namespace std;

int main() 
{
    // Вывод заголовка таблицы
    cout << "Symbol\tNumber" << endl;

    // Используем цикл for для вывода строчных символов
    for (char c = 'a'; c <= 'z'; c++) 
    {
        cout << c << "\t" << static_cast<int>(c) << endl;
    }

    // Используем цикл for для вывода прописных символов
    for (char c = 'A'; c <= 'Z'; c++) 
    {
        cout << c << "\t" << static_cast<int>(c) << endl;
    }

    // Используем цикл for для вывода цифр
    for (char c = '0'; c <= '9'; c++) 
    {
        cout << c << "\t" << static_cast<int>(c) << endl;
    }

    return 0;
}
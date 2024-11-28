#include <iostream>
#include <iomanip> // Для std::setprecision

using namespace std;

// Функции для конвертации валют
double yenToUsd(double yen) 
{
    return yen * 0.0069; // Примерный курс йен к доллару
}

double euroToUsd(double euro) 
{
    return euro * 1.06; // Примерный курс евро к доллару
}

double poundToUsd(double pound) 
{
    return pound * 1.24; // Примерный курс фунтов стерлингов к доллару
}

int main() 
{
    int choice;
    double amount;

    cout << "Select the currency to convert:" << endl;
    cout << "1. Yen" << endl;
    cout << "2. Euro" << endl;
    cout << "3. Pounds sterling" << endl;

    cout << "Enter the currency number (1/2/3): ";
    cin >> choice;

    cout << "Enter the amount to convert: ";
    cin >> amount;

    switch (choice) 
    {
        case 1:
            cout << fixed << setprecision(2); // Устанавливаем формат вывода с 2 знаками после запятой
            cout << amount << " Yen = " << yenToUsd(amount) << " dollar" << endl;
            break;
        case 2:
            cout << fixed << setprecision(2);
            cout << amount << " Euro = " << euroToUsd(amount) << " dollar" << endl;
            break;
        case 3:
            cout << fixed << setprecision(2);
            cout << amount << " Pounds sterling = " << poundToUsd(amount) << " dollar" << endl;
            break;
        default:
            cout << "Please try again." << endl;
            break;
    }

    return 0;
}
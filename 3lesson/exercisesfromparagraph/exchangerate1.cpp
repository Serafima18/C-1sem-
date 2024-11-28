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

double yuanToUsd(double yuan) 
{
    return yuan * 0.15; // Примерный курс юаней к доллару
}

double sekToUsd(double sek) 
{
    return sek * 0.10; // Примерный курс шведских крон к доллару
}

int main() 
{
    int choice;
    double amount;

    cout << "Select the currency to convert:" << endl;
    cout << "1. Yen" << endl;
    cout << "2. Euro" << endl;
    cout << "3. Pounds sterling" << endl;
    cout << "4. Yuan" << endl;
    cout << "5. Swedish Krona" << endl;

    cout << "Enter the currency number (1/2/3/4/5): ";
    cin >> choice;

    cout << "Enter the amount to convert: ";
    cin >> amount;

    switch (choice) 
    {
        case 1:
            cout << fixed << setprecision(2);
            cout << amount << " Yen = " << yenToUsd(amount) << " USD" << endl;
            break;
        case 2:
            cout << fixed << setprecision(2);
            cout << amount << " Euro = " << euroToUsd(amount) << " USD" << endl;
            break;
        case 3:
            cout << fixed << setprecision(2);
            cout << amount << " Pounds sterling = " << poundToUsd(amount) << " USD" << endl;
            break;
        case 4:
            cout << fixed << setprecision(2);
            cout << amount << " Yuan = " << yuanToUsd(amount) << " USD" << endl;
            break;
        case 5:
            cout << fixed << setprecision(2);
            cout << amount << " Swedish Krona = " << sekToUsd(amount) << " USD" << endl;
            break;
        default:
            cout << "Please try again." << endl;
            break;
    }

    return 0;
}

// Использование switch делает код более организованным и легче читаемым по сравнению с множественными if-else. 
// Когда количество вариантов выбора увеличивается, switch помогает быстро понять логическую структуру
#include "std_lib.h"

constexpr char currency{'$'};

long int iround(double n){
    return (n < 0.0) ? (n - 0.5) : (n + 0.5);
}

class Money{
public:
    class Division_by_zero { }; // пользовательское исключение

    Money(long int units, long int cents); // конструктор на единицах измерения и центах
    Money(long int amount); // конструктор по количеству центов
    Money(); // конструктор по умолчанию, значение 0

    long int amount() const { return m_amount; };
    
    long int units() const { return m_amount/100; }; // извлечение данных
    long int cents() const { return m_amount%100; };
private:
    long int m_amount; // сумма в деньгах в центах
};

Money::Money(long int units, long int cents) : m_amount{units*100+cents} { };
Money::Money(long int amount) : m_amount{amount} { };
Money::Money() : m_amount{0} { };

Money operator-(const Money& rhs){
    return Money{-rhs.amount()};
}

Money operator+(const Money& lhs, const Money& rhs){
    return Money{lhs.amount()+rhs.amount()};
}

Money operator-(const Money& lhs, const Money& rhs){
    return Money{lhs.amount()-rhs.amount()};
}

Money operator*(const Money& lhs, double rhs){
    return Money{ iround(lhs.amount()*rhs) };
}

Money operator*(double lhs, const Money& rhs){
    return Money{ iround(lhs*rhs.amount()) };
}

Money operator/(const Money& lhs, double rhs){
    if (rhs == 0) throw Money::Division_by_zero{};

    return Money{ iround(lhs.amount()/rhs) };
}

double operator/(const Money& lhs, const Money& rhs){
    if (rhs.amount() == 0) throw Money::Division_by_zero{};

    return (double(lhs.amount())/rhs.amount());
}

bool operator==(const Money& lhs, const Money& rhs){
    return (lhs.amount() == rhs.amount());
}

bool operator!=(const Money& lhs, const Money& rhs){
    return (lhs.amount() != rhs.amount());
}

ostream& operator<<(ostream& os, const Money& money){
    os << currency << money.units() << '.';
    if (abs(money.cents()) < 10) os << '0';
    os << abs(money.cents());

    return os;
}

istream& operator>>(istream& is, Money& money){
    long int units{0};
    char cur, dot;
    char d, u;

    is >> cur >> units >> dot >> d >> u;
    if (!is) return is;
    if (cur != currency || dot != '.' || !isdigit(d) || !isdigit(u)) {
        is.clear(ios_base::failbit);
        return is;
    }
    // буду читать два символа и составлять центы
    int cents{(d-'0')*10+(u-'0')};

    if (units < 0) cents = -cents; // только единицы измерения имеют знак, но центы имеют значение
    money = Money{(units*100)+cents};

    return is;
}

int main()
try{

    // тест Money*double, double*Money, Money/Money, Money/double, Money-Money
    Money budget{10000,0};
    Money wage{150,0};
    long int months{18};
    long int workers{ iround(budget/(wage*months)) };
    Money surplus{budget-(workers*wage*months)};
    cout << "The project's budget ascends to " << budget
         << " and it will be developed during " << months << " months.\n"
         << "Each developer get " << wage << " per month. "
         << "So we can hire " << workers << " developers.\n"
         << "The spare budget will be " << surplus << ".\n";

    cout << '\n';

    // тест Money*double, Money+Money
    Money product{137,0};
    double vat = 0.22;
    Money total{product+(product*vat)};
    cout << "You have bought and paid by transference " << product
         << " for a product. But you forgot the VAT (" << vat*100
         << "%).\n" << "With VAT applied the product costs " << total
         << " so you debt " << product-total << '\n';

    cout << '\n';

    // тест >> и << операторы;
    cout << "Write some quantities (examples: $123.04 or $-10.10, two digits"
         << " for cents are mandatory. Quit with Ctrl+D).\n> ";
    Money input{0};
    while (cin) {
        cin >> input;
        if (cin.eof()) break;
        if (cin.fail()) {
            cout << "Bad input format\n> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cout << '\t' << input << "\n> ";
        }
    }

    cout << "\nBye!\n";

    return 0;
}

catch(Money::Division_by_zero& e){
    cerr << "Money class: division by zero\n";
    return 1;
}

catch(exception& e){
    cerr << e.what() << '\n';
    return 2;
}

catch(...){
    cerr << "Unknown exception!!\n";
    return 3;
}
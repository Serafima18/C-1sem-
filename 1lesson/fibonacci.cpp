#include <iostream>

using namespace std;

int fibonacci(int n) 
{
    if (n <= 0) 
    {
        throw invalid_argument("n must be a natural number.");
    }
    if (n == 1 || n == 2) 
    {
        return 1;
    }

    int a = 1; // F1
    int b = 1; // F2
    int fib = 0;

    for (int i = 3; i <= n; ++i) 
    {
        fib = a + b; // F(n) = F(n-1) + F(n-2)
        a = b;       // Сдвигаем F(n-1)
        b = fib;     // Сдвигаем F(n)
    }

    return fib;
}

int main() 
{
    int n;
    cout << "enter the fibonacci number (n): ";
    cin >> n;

    try 
    {
        int result = fibonacci(n);
        cout << "fibonacci number F(" << n << ") = " << result << endl;
    } catch (const invalid_argument& ia) 
    {
        cerr << "error: " << ia.what() << endl;
    }

    return 0;
}
// Необходимо ли хранить в памяти все вычисленные числа Фибоначчи? Нет, это не обязательно хранить, 
// потому что нам нужны в решении задачи только последние два числа последовательности.
#include "std_lib.h"

void print(const string& label, const vector<int>& data){
// только считывание аргументов
    cout << label << ": { ";
    for (int i : data) cout << i << ' ';
    cout << "}\n";
}

int check_add(int a, int b) {
    if (((b > 0) && (a > (numeric_limits<int>::max() - b))) ||
        ((b < 0) && (a < (numeric_limits<int>::min() - b))))
            error("check_add(): integer add overflows.");
    else
        return a+b;
}

void fibonacci(int x, int y, vector<int>& v, int n){
// Преобразование последовательности Фибоначчи из n значений в v, начиная со значений x
    if (v.size() != 0) error("fibonacci(): Non empty vector passed as argument.");
    if (n < 2) error("fibonacci(): n must be al least 2.");

    v.push_back(x);
    v.push_back(y);

    for (int i = 2; i < n; ++i) v.push_back(check_add(v[i-2],v[i-1]));
}

int main()
// тест
try {
    vector<int> data;

    fibonacci(1, 2, data, 10);
    print("Fib(10)", data);

    data.clear();
    fibonacci(-2,-2, data, 10);
    print("Test with negatives", data);

    data.clear();
    fibonacci(1, 2, data, 20);
    print("Test", data);

    data.clear();
    fibonacci(-5, 4, data, 20);
    print("Test with two signs", data);

    data.clear();       
    fibonacci(1, 2, data, 50);
    print("Test Fib(50)", data);

    return 0;
}

catch(exception& e){
    cerr << e.what() << '\n';
    return 1;
}

catch(...){
    cerr << "Unknwon exception!!\n";
    return 2;
}
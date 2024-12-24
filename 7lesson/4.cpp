#include "std_lib.h"

void print(const string& label, const vector<int>& data){
    cout << label << ": { ";
    for (int i : data) cout << i << ' ';
    cout << "}\n";
}

int check_add(int a, int b){
// добавляет два целых числа, выполняющих контроль переполнения, чтобы избежать неопределенного поведения.
    if (((b > 0) && (a > (numeric_limits<int>::max() - b))) ||
        ((b < 0) && (a < (numeric_limits<int>::min() - b))))
            error("check_add(): integer add overflows.");
    else return a+b;
}

void fibonacci(int x, int y, vector<int>& v, int n){
    if (v.size() != 0) error("fibonacci(): Non empty vector passed as argument.");
    if (n < 2) error("fibonacci(): n must be al least 2.");

    v.push_back(x);
    v.push_back(y);

    try {
        for (int i = 2; i < n; ++i) v.push_back(check_add(v[i-2],v[i-1]));
    }
    catch(exception& e){
       cerr << e.what() << '\n';
    }
}

int main()
try {
    vector<int> data;
    int max{0};         // отслеживание максимального значения
    int min{0};         // отслеживание минимального значения
    int begin{-200};    // значение из расчета последовательностей Фибоначчи
    int end{200};       // значение для вычисления последовательностей Фибоначчи
    int seq_size{50};   // элементы последовательности фибоначчи. К примеру 50

    for (int i = begin; i < end; ++i) {
        fibonacci(i, i+1, data, seq_size);
        int& val = data[data.size()-1];
        if (val > max) max = val;
        if (val < min) min = val;
        data.clear(); // пустой вектор для следующего цикла
    }

    cout << "Maximum integer approximate: " << max;
    cout << " (real limit " << numeric_limits<int>::max() << ")\n";
    cout << "Minimum integer approximate: " << min;
    cout << " (real limit " << numeric_limits<int>::min() << ")\n";

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
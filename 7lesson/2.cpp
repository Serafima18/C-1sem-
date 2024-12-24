#include "std_lib.h"

void print(const string& label, const vector<int>& data){
    cout << label << ": { ";
    for (int i : data)
        cout << i << ' ';
    cout << "}\n";
}

int main(){ // тест
    vector<int> sample;
    string label{"data"};

    // выборка
    for (int i = 0; i < 100; ++i) {
        sample.push_back(i);
    }

    // некоторые примеры
    print(label, sample);
    print("A pair", vector<int> {10, 99});
    print("Empty", vector<int> {});

    return 0;
}
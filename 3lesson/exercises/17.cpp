#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of numbers: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of numbers must be greater than 0." << endl;
        return 1;
    }

    vector<int> numbers(n);
    cout << "Enter " << n << " positive numbers:" << endl;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int min_num = numeric_limits<int>::max();
    int max_num = numeric_limits<int>::min();
    unordered_map<int, int> frequency;

    for (const auto& num : numbers) {
        if (num < min_num) {
            min_num = num;
        }
        if (num > max_num) {
            max_num = num;
        }
        frequency[num]++;
    }

    // Найти моду
    int mode = numbers[0];
    int max_count = 0;
    
    for (const auto& entry : frequency) {
        if (entry.second > max_count) {
            max_count = entry.second;
            mode = entry.first;
        }
    }

    cout << "Max number: " << min_num << endl;
    cout << "Min number: " << max_num << endl;
    cout << "Moda: " << mode << endl;

    return 0;
}
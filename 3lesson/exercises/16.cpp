#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;

    cout << "Enter the number of numbers: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of numbers must be positive!" << endl;
        return 1;
    }

    vector<int> numbers(n);
    cout << "Enter " << n << " positive numbers:" << endl;

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int maxNum = numbers[0];
    int minNum = numbers[0];
    unordered_map<int, int> frequency;

    for (int num : numbers) {
        if (num > maxNum) {
            maxNum = num;
        }
        if (num < minNum) {
            minNum = num;
        }
        frequency[num]++;
    }

    int mode = numbers[0];
    int maxCount = 0;

    for (const auto& pair : frequency) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    cout << "Max number: " << maxNum << endl;
    cout << "Min number: " << minNum << endl;
    cout << "Moda: " << mode << " (occurs " << maxCount << " times)" << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    // Словарь для дней недели и их синонимов
    unordered_map<string, string> day_map = {
        {"Sunday", "Sunday"}, {"Mon", "Monday"}, {"Monday", "Monday"},
        {"Tue", "Tuesday"}, {"Tuesday", "Tuesday"}, 
        {"Wed", "Wednesday"}, {"Thu", "Thursday"}, {"Thursday", "Thursday"}, 
        {"Fri", "Friday"}, {"Friday", "Friday"}, 
        {"Sat", "Saturday"}, {"Saturday", "Saturday"}
    };

    // Вектор, чтобы хранить значения для каждого дня недели
    vector<vector<int>> week_values(7); // 0 - Sunday, 1 - Monday, ..., 6 - Saturday
    int rejected_count = 0;

    string input;
    cout << "Enter the pairs (day of the week, value): ";
    getline(cin, input);
    stringstream ss(input);
    string day;
    int value;

    // Чтение пар (день, значение)
    while (ss >> day >> value) {
        // Приводим день к формату с заглавной буквы
        day[0] = toupper(day[0]);
        for (size_t i = 1; i < day.size(); i++) {
            day[i] = tolower(day[i]);
        }

        // Проверка на наличие дня в словаре
        if (day_map.find(day) != day_map.end()) {
            string normalized_day = day_map[day];
            int day_index = (normalized_day == "Sunday") ? 0 :
                            (normalized_day == "Monday") ? 1 :
                            (normalized_day == "Tuesday") ? 2 :
                            (normalized_day == "Wednesday") ? 3 :
                            (normalized_day == "Thursday") ? 4 :
                            (normalized_day == "Friday") ? 5 :
                            (normalized_day == "Saturday") ? 6 : -1;

            if (day_index != -1) {
                week_values[day_index].push_back(value); // Сохраняем значение
            }
        } else {
            rejected_count++; // Увеличиваем счетчик основанных на неверных днях
        }
    }

    // Печатаем сумму для каждого дня недели
    for (int i = 0; i < 7; ++i) {
        int sum = 0;
        for (int val : week_values[i]) {
            sum += val;
        }
        cout << "The amount for " << (i == 0 ? "Sunday" : (i == 1 ? "Monday" :
                 (i == 2 ? "Tuesday" : (i == 3 ? "Wednesday" :
                 (i == 4 ? "Thursday" : (i == 5 ? "Friday" : "Saturday")))))) << ": " << sum << endl;
    }

    // Вывод количества отвергнутых чисел
    cout << "The number of rejected numbers: " << rejected_count << endl;

    return 0;
}
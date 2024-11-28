#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    const int totalCells = 64;
    long long currentGrains = 1; // Зерна на текущей клетке
    long long totalGrains = 0; // Общее количество зерен
    int cellsFilled = 0; // Количество заполненных клеток

    // Максимальные значения для int и double
    const long long maxInt = std::numeric_limits<int>::max();
    const double maxDouble = std::numeric_limits<double>::max();

    int maxCellsInt = 0;
    int maxCellsDouble = 0;

    // Проверяем на сколько клеток можно заполнить, сохраняя результаты в типах int и double
    for (int i = 0; i < totalCells; ++i) {
        totalGrains += currentGrains;
        cellsFilled++;

        if (totalGrains <= maxInt) {
            maxCellsInt = cellsFilled; // Сохраняем, если еще в диапазоне int
        }

        if (totalGrains <= maxDouble) {
            maxCellsDouble = cellsFilled; // Сохраняем, если еще в диапазоне double
        }

        currentGrains *= 2; // Удвоение количества зерен на следующей клетке
    }

    std::cout << "Maximum cells for int: " << maxCellsInt << std::endl;
    std::cout << "Maximum cells for double: " << maxCellsDouble << std::endl;

    return 0;
}
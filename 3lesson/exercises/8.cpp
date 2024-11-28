#include <iostream>
#include <iomanip>

int main() {
    const int totalCells = 64;
    long long currentGrains = 1; // Зерна на текущей клетке
    long long totalGrains = 0; // Общее количество зерен
    int cellsFilled = 0; // Количество заполненных клеток

    // Пороговые значения для проверки
    const long long thresholds[] = {1000, 1000000, 1000000000};
    const int thresholdCount = sizeof(thresholds) / sizeof(thresholds[0]);
    bool thresholdsReached[thresholdCount] = {false}; // Флаги для достигнутых значений

    std::cout << "Cell | Current Grains | Total Grains" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    for (int i = 0; i < totalCells; ++i) {
        totalGrains += currentGrains;
        cellsFilled++;

        std::cout << std::setw(4) << (i + 1) << " | " 
                  << std::setw(15) << currentGrains << " | " 
                  << std::setw(12) << totalGrains << std::endl;

        // Проверка на достигнутые пороги
        for (int j = 0; j < thresholdCount; ++j) {
            if (!thresholdsReached[j] && totalGrains >= thresholds[j]) {
                std::cout << "Reached " << thresholds[j] << " grains after filling " 
                          << cellsFilled << " cells." << std::endl;
                thresholdsReached[j] = true;
            }
        }

        currentGrains *= 2; // Удвоение количества зерен на следующей клетке
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void drawHistogram(const std::vector<std::pair<int, int>>& data) {
    std::cout << "Рост (см)  Количество людей\n";
    for (const auto& [height, count] : data) {
        std::cout << height << ": ";
        for (int i = 0; i < count; ++i) {
            std::cout << "#";
        }
        std::cout << " (" << count << ")\n";
    }
}

int main() {
    std::vector<std::pair<int, int>> data = {
        {170, 7}, {175, 9}, {180, 23}, {185, 17}, {190, 6}, {195, 1}
    };

    // Сохранение данных в файл
    std::ofstream outFile("height_data.txt");
    for (const auto& [height, count] : data) {
        outFile << height << "," << count << "\n";
    }
    outFile.close();

    // Чтение данных из файла
    std::ifstream inFile("height_data.txt");
    std::vector<std::pair<int, int>> readData;
    int height, count;
    char comma;
    while (inFile >> height >> comma >> count) {
        readData.emplace_back(height, count);
    }
    inFile.close();

    drawHistogram(readData);
    return 0;
}
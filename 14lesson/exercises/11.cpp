#include <iostream>
#include <vector>
#include <string>
#include <map>

class TemperaturePlot {
public:
    TemperaturePlot(const std::string& title) : title(title) {}

    void addCityData(const std::string& city, const std::vector<double>& temps) {
        cityData[city] = temps;
    }

    void draw() const {
        std::cout << title << "\n";
        std::cout << "Месяц\t\t";
        for (const auto& city : cityData) {
            std::cout << city.first << "\t";
        }
        std::cout << "\n";

        for (int month = 0; month < 12; ++month) {
            std::cout << month + 1 << "\t\t";
            for (const auto& city : cityData) {
                std::cout << city.second[month] << "\t\t";
            }
            std::cout << "\n";
        }
    }

private:
    std::string title;
    std::map<std::string, std::vector<double>> cityData;
};

int main() {
    TemperaturePlot tempPlot("Средняя температура по месяцам");

    std::vector<double> cambridgeUK = {5, 6, 9, 12, 15, 18, 21, 21, 17, 13, 9, 6};
    std::vector<double> cambridgeMA = {1, 2, 6, 10, 15, 20, 24, 23, 18, 12, 7, 2};

    tempPlot.addCityData("Кембридж, Англия", cambridgeUK);
    tempPlot.addCityData("Кембридж, Массачусетс", cambridgeMA);

    tempPlot.draw();
    return 0;
}
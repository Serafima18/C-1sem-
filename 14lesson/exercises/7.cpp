#include <iostream>
#include <vector>
#include <string>
#include <map>

class Histogram {
public:
    Histogram(const std::string& title) : title(title) {}

    void addDataPoint(const std::string& label, int value, const std::string& color) {
        data[label] = value;
        colors[label] = color;
    }

    void draw() const {
        std::cout << title << std::endl;
        for (const auto& [label, value] : data) {
            std::cout << label << ": ";
            // Здесь можно представить цвет в виде текста
            std::cout << "[" << colors.at(label) << "] ";
            for (int i = 0; i < value; ++i) {
                std::cout << "#";
            }
            std::cout << " (" << value << ")\n";
        }
    }

private:
    std::string title;
    std::map<std::string, int> data;
    std::map<std::string, std::string> colors;
};

int main() {
    Histogram hist("Пример гистограммы");
    hist.addDataPoint("Категория 1", 5, "Красный");
    hist.addDataPoint("Категория 2", 10, "Синий");
    hist.addDataPoint("Категория 3", 3, "Зеленый");
    
    hist.draw();
    return 0;
}
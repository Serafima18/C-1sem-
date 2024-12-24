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
    Histogram hist("Гистограмма роста людей (в дюймах)");
    
    // Исходные данные о росте в см
    std::vector<int> heights_cm = {160, 165, 170, 175, 180, 185, 190, 165, 170, 175, 180};
    
    // Масштабируем данные: 1 см = 0.393701 дюйма
    for (int height : heights_cm) {
        int height_in_inches = static_cast<int>(height * 0.393701);
        hist.addDataPoint("Рост " + std::to_string(height) + " см", height_in_inches, "Синий");
    }

    hist.draw();
    return 0;
}
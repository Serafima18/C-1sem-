#include <iostream>
#include <vector>

class Histogram {
public:
    Histogram(const std::vector<int>& data) : data(data) {}

    void draw() {
        for (int value : data) {
            std::cout << std::string(value, '*') << std::endl; // просто выводим звездочки
        }
    }
    
private:
    std::vector<int> data;
};

int main() {
    std::vector<int> data = {7, 9, 23, 17, 6, 1};
    Histogram hist(data);
    hist.draw();
    return 0;
}
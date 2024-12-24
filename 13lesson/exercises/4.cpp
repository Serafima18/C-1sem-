#include <iostream>

class Circle {
public:
    virtual void move(int x, int y) {
        std::cout << "Moving Circle to (" << x << ", " << y << ")" << std::endl;
    }
};

class Immobile_Circle : public Circle {
public:
    void move(int x, int y) override {
        std::cout << "Immobile Circle cannot be moved!" << std::endl;
    }
};

int main() {
    Immobile_Circle immobileCircle;
    immobileCircle.move(10, 20); // Вывод: Immobile Circle cannot be moved!
    
    return 0;
}
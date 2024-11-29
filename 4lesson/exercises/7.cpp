#include <iostream>
#include <cmath>
#include <stdexcept>

void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        throw std::runtime_error("The equation has no real roots.");
    }

    double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double root2 = (-b - std::sqrt(discriminant)) / (2 * a);

    std::cout << "The roots of the equation: " << root1 << " and " << root2 << std::endl;
}

int main() {
    double a, b, c;

    std::cout << "Enter the coefficients a, b and c: ";
    std::cin >> a >> b >> c;

    try {
        solveQuadratic(a, b, c);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    double pi_over_4 = 0;
    for (int i = 0; i < 10000; ++i) {
        if (i % 2 == 0) {
            pi_over_4 += 1.0 / (2 * i + 1);
        } else {
            pi_over_4 -= 1.0 / (2 * i + 1);
        }
        std::cout << "Approximation of pi after " << i << " terms: " << (pi_over_4 * 4) << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
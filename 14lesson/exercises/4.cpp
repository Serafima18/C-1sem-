#include <iostream>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x, y1, y2, y3, y4;

    for (double i = -10; i <= 10; i += 0.1) {
        x.push_back(i);
        y1.push_back(sin(i));
        y2.push_back(cos(i));
        y3.push_back(sin(i) + cos(i));
        y4.push_back(sin(i) * sin(i) * cos(i) * cos(i));
    }

    plt::plot(x, y1, "r-", {{"label", "sin(x)"}});
    plt::plot(x, y2, "g-", {{"label", "cos(x)"}});
    plt::plot(x, y3, "b-", {{"label", "sin(x) + cos(x)"}});
    plt::plot(x, y4, "c-", {{"label", "sin^2(x) * cos^2(x)"}});
    plt::legend();
    plt::show();
    return 0;
}
#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<double> distances;
    double distance;
    
    std::cout << "Enter distances (type 'end' to finish): " << std::endl;
    while (std::cin >> distance) {
        distances.push_back(distance);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    double totalDistance = 0;
    double minDistance = std::numeric_limits<double>::max();
    double maxDistance = std::numeric_limits<double>::lowest();
    
    for (size_t i = 0; i < distances.size(); ++i) {
        totalDistance += distances[i];
        if (i > 0) {
            double neighboringDistance = std::abs(distances[i] - distances[i - 1]);
            if (neighboringDistance < minDistance) minDistance = neighboringDistance;
            if (neighboringDistance > maxDistance) maxDistance = neighboringDistance;
        }
    }

    double averageDistance = (distances.size() > 1) ? totalDistance / (distances.size() - 1) : 0;

    std::cout << "Total distance: " << totalDistance << std::endl;
    std::cout << "Minimum distance between neighboring cities: " << minDistance << std::endl;
    std::cout << "Maximum distance between neighboring cities: " << maxDistance << std::endl;
    std::cout << "Average distance between neighboring cities: " << averageDistance << std::endl;

    return 0;
}
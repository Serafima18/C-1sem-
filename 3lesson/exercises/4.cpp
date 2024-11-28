#include <iostream>
#include <string>

int main() {
    int low = 1, high = 100;
    std::string response; // Измените тип на std::string

    std::cout << "Think of a number between " << low << " and " << high << ". Type 'yes' if I guess it right, otherwise type 'no'." << std::endl;

    while (low < high) {
        int mid = (low + high) / 2;
        std::cout << "Is the number greater than " << mid << "? (yes/no): ";
        std::cin >> response;

        if (response == "yes") {
            low = mid + 1; // Если число больше mid, обновляем низкую границу
        } else {
            high = mid; // Если число меньше или равно mid, обновляем высокую границу
        }
    }

    std::cout << "Is your number " << low << "? (yes/no): ";
    std::cin >> response;

    if (response == "yes") {
        std::cout << "I guessed your number!" << std::endl;
    } else {
        std::cout << "It seems there was an error." << std::endl;
    }

    return 0;
}
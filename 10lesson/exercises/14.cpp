#include <iostream>
#include <fstream>
#include <iomanip> // для std::setprecision и std::scientific
#include <vector>

int main() {
    // Открытие входного и выходного файлов
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile) {
        std::cerr << "The file could not be opened input.txt" << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "The file could not be opened output.txt" << std::endl;
        return 1;
    }

    std::vector<double> numbers;
    double number;

    // Считывание чисел из файла
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    // Запись чисел в выходной файл в научном формате
    outputFile << std::scientific << std::setprecision(8);

    int count = 0;
    for (const double& num : numbers) {
        outputFile << std::setw(20) << num;

        count++;
        // Если достигли 4 значений, переносим строку
        if (count % 4 == 0) {
            outputFile << std::endl;
        }
    }

    // Если было меньше 4 значений в последней строке
    if (count % 4 != 0) {
        outputFile << std::endl;
    }

    outputFile.close();

    std::cout << "The numbers have been successfully written to the file output.txt ." << std::endl;

    return 0;
}
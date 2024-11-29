#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Определяем массивы для имен существительных, глаголов и союзов
vector<string> nouns = {"the birds", "the fish", "C++"};
vector<string> verbs = {"fly", "swim", "rules"};
vector<string> conjunctions = {"and", "or", "but"};

// Функция для генерации сложносочиненного предложения
void generateCompoundSentence() {
    // Генерируем случайные индексы для подбора существительных и глаголов
    int noun1Index = 0; // для "the birds"
    int verb1Index = 0; // для "fly"
    int noun2Index = 1; // для "the fish"
    int verb2Index = 1; // для "swim"
    int conjIndex = 2;  // для "but"

    // Формируем предложение
    string sentence = nouns[noun1Index] + " " + verbs[verb1Index] + " " +
                      conjunctions[conjIndex] + " " +
                      nouns[noun2Index] + " " + verbs[verb2Index] + ".";

    // Выводим предложение
    cout << sentence << endl;
}

int main() {
    generateCompoundSentence();
    return 0;
}
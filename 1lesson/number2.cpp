#include <iostream>

using namespace std;

int main() 
{
    cout << "enter a number: ";
    string input;
    cin >> input;

    string mirrored;
    
    for (int i = input.length() - 1; i >= 0; --i) 
    {
        mirrored += input[i];
    }

    cout << "a mirror copy: " << mirrored << '\n';

    return 0;
}
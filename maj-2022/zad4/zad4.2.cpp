#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string zadNumber = "4.2";
    fstream file;
    int fValue;
    vector <int> primeNumbers;

    file.open("additional-programs/prime-numbers.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            file >> fValue;
            primeNumbers.push_back(fValue);
        }
    }
    file.close();

    file.open("../przyklad.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            file >> fValue;
            cout << fValue << endl;
        }
    }
    
    // Sprawdzanie która liczba jakie ma liczby pierwsze i gitarka
    
    // cout << zadNumber + ": " <<  << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    fstream file;
    int maxPrimeNumber = 100000;
    vector <int> primeNumbers;

    bool isPrime;

    for (int number = 2; number <= maxPrimeNumber; number++)
    {
        isPrime = true;
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime) 
        {
            primeNumbers.push_back(number);
        }
    }

    file.open("../prime-numbers.txt", ios::out);

    if (file.good())
    {
        for (int i = 0; i < primeNumbers.size()-1; i++)
        {
            file << primeNumbers[i] << "\n";
        }
        file << primeNumbers.back();
    }

    return 0;
}

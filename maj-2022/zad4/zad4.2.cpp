#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    string zadNumber = "4.2";
    fstream file;
    int fValue;
    vector <int> allNumbers;
    vector <int> primeNumbers;

    // Pobieranie wszystkich liczb pierwszych z pliku
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

    file.open("liczby.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            file >> fValue;
            allNumbers.push_back(fValue);
        }
    }

    vector <int> numbersVector[allNumbers.size()];

    // Szukanie czynników pierwszych dla każdej liczby
    for (int i = 0; i < allNumbers.size(); i++)
    {
        int analyzedNumber = allNumbers[i];
        int j = 0;
        vector <int> helpfulVector;
        helpfulVector.clear();
        while (true)
        {
            if (analyzedNumber < primeNumbers[j])
            {
                break;
            }
            if (analyzedNumber % primeNumbers[j] == 0)
            {
                analyzedNumber = analyzedNumber / primeNumbers[j];
                helpfulVector.push_back(primeNumbers[j]);
            }
            else
            {
                j++;
            }
        }
        sort(helpfulVector.begin(), helpfulVector.end());
        numbersVector[i] = helpfulVector;
    }

    // X to liczba mająca najwięcej współczynników pierwszych
    // Y to liczba mająca najwięcej RÓŹNYCH współczynników pierwszych
    // Z to liczba pomocnicza

    int X;
    int XNumber;

    int Y;
    int YNumber;

    int Z = 0;
    int ZNumber = 0;

    // Sprawdzanie, która liczba ma najwięcej
    for (int i = 0; i < allNumbers.size(); i++)
    {
        if (numbersVector[i].size() > ZNumber)
        {
            ZNumber = numbersVector[i].size();
            Z = allNumbers[i];
        }
    }
    X = Z;
    XNumber = ZNumber;

    // Sprawdzanie, która liczba ma najwięcej różnych
    Z = 0;
    ZNumber = 0;

    for (int i = 0; i < allNumbers.size(); i++)
    {
        int counter = 1;
        int a = numbersVector[i][0];

        for (int j = 1; j < numbersVector[i].size(); j++)
        {
            if (a != numbersVector[i][j])
            {
                counter++;
                a = numbersVector[i][j];
            }
        }

        if (counter > ZNumber)
        {
            ZNumber = counter;
            Z = allNumbers[i];
        }
    }

    Y = Z;
    YNumber = ZNumber;



    cout << zadNumber + ": " << X << " " << XNumber << " " << Y << " " << YNumber << endl;

    return 0;
}

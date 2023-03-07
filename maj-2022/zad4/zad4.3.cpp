#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /* (x, y , z) jest dobre gdy:
    y % x = 0
    z % y = 0
    x != y != z
    */
    string zadNumber = "Zad4.3";
    fstream file;
    int u, w, x, y, z;
    int fValue;
    vector <int> numbers;
    int three = 0, five = 0;

    // Dodajemy wszystkie liczby do vectora
    file.open("liczby.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            file >> fValue;
            numbers.push_back(fValue);
        }
    }
    file.close();

    // Szukamy trojek (x, y, z)
    file.open("trojki.txt", ios::out);
    if (!file.good()) return 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        x = numbers[i];
        if (x == 0) continue;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (x == numbers[j]) continue;
            if (numbers[j] % x != 0) continue;

            y = numbers[j];
            if (y == 0) continue;

            for (int k = 0; k < numbers.size(); k++)
            {
                if (x == numbers[k]) continue;
                if (y == numbers[k]) continue;
                if (numbers[k] % y != 0) continue;

                z = numbers[k];
                three++;
                file << x << " " << y << " " << z << "\n";
            }
        }
    }
    file.close();

    // Szukamy piatek (x, y, z, u, w)
    for (int i = 0; i < numbers.size(); i++)
    {
        x = numbers[i];
        if (x == 0) continue;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (x == numbers[j]) continue;
            if (numbers[j] % x != 0) continue;

            y = numbers[j];
            if (y == 0) continue;

            for (int k = 0; k < numbers.size(); k++)
            {
                if (x == numbers[k]) continue;
                if (y == numbers[k]) continue;
                if (numbers[k] % y != 0) continue;

                z = numbers[k];
                for (int m = 0; m < numbers.size(); m++)
                {
                    if (x == numbers[m]) continue;
                    if (y == numbers[m]) continue;
                    if (z == numbers[m]) continue;
                    if (numbers[m] % z != 0) continue;

                    u = numbers[m];
                    for (int n = 0; n < numbers.size(); n++)
                    {
                        if (x == numbers[n]) continue;
                        if (y == numbers[n]) continue;
                        if (z == numbers[n]) continue;
                        if (u == numbers[n]) continue;
                        if (numbers[n] % u != 0) continue;

                        w = numbers[n];

                        five++;
                    }
                }

            }
        }
    }

     cout << zadNumber + ": a) " << three << endl;
     cout << zadNumber + ": b) " << five << endl;

    return 0;
}

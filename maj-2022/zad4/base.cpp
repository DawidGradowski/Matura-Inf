#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string zadNumber = "";
    fstream file;
    int fValue;
    file.open("../przyklad.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            file >> fValue;
            cout << fValue << endl;
        }
    }
    
    // cout << zadNumber + ": " <<  << endl;

    return 0;
}

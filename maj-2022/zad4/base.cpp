#include <iostream>
#include <fstream>

using namespace std;

int main()
{
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
    
    return 0;
}

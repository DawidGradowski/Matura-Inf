#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string zadNumber = "4.1";
    fstream file;
    string strValue;
    int count = 0;
    string firstNumber = "None";

    file.open("../przyklad.txt", ios::in);
    if (file.good())
    {
        while (!file.eof())
        {
            file >> strValue;
            if (strValue[0] == strValue[strValue.size()-1])
            {
                count++;
                if (firstNumber == "None")
                {
                    firstNumber = strValue;
                }
            }
        }
        cout << zadNumber + ": " << count << " " << firstNumber << endl;
        file.close();
    }
    
    return 0;
}

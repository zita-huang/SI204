/*******************
Filename: part1.cpp
Author: Zita Huang (m272898)
Lab04 Part 1
********************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // For output formatting
using namespace std;

int main()
{
    string file;
    cin >> file;

    ifstream fin(file);

    //Error message if file does not exist
    if (!fin)
    {
        cout << "Could not open file '" << file << "'" << endl;
        return 1;
    }

    //Declaring the variables and strings
    double Total = 0.0;
    int count = 0;
    string time, temp;
    fin >> time >> temp;

    // While loop to convert Celisus to Fahrenheit
    while (fin >> time >> temp)
    {
        double F = 0.0;
        fin >> F;

        F = ((9.0/5.0)*F)+32.0;
        Total += F;
        count++;
    }

    //Outputing filename and average
    cout << "file: " << file << endl;
    cout << "ave: " << (Total/count) << endl;
    
    return 0;
}
        
/*******************
Filename: part2.cpp
Author: MIDN Zita Huang (m272898)
Lab04 Part 2
********************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string file;
    cin >> file;

    ifstream fin(file);

    if (!fin)
    {
        cout << "Could not open file '" << file << "'" << endl;
        return 1;
    }

    double Total = 0.0, fmax = 0.0, fmin = 0.0;
    int count = 0;
    string temp, time, date, maxdate, mindate;
    fin >> time >> temp;

    // Process each line in the file
    while (fin >> time >> temp)
    {
        double F = 0.0;
        fin >> F;

        F = ((9.0/5.0)*F)+32.0;
        Total += F;

        if(count == 0)
        {
            fmax = F;
            fmin = F;
            maxdate = time;
            mindate = time;
        }

        count++;

        if(F > fmax)
        {
            fmax = F;
            maxdate = time;
        }

        if(F < fmin)
        {
            fmin = F;
            mindate = time;
        }
    }

    cout << "file: " << file << endl;
    cout << "ave: " << (Total/count) << endl;
    cout << "min: " << fmin << " on " << mindate << endl;
    cout << "max: " << fmax << " on " << maxdate << endl;
    
    return 0;
}
        
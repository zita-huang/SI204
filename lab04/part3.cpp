/****************
Filename: part3.cpp
Author: MIDN Zita Huang (m272898)
Lab4 Part 3
*****************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string file, outfile;
    cin >> file >> outfile;

    ifstream fin(file);

    if (!fin)
    {
        cout << "Could not open file '" << file << "'" << endl;
        return 1;
    }

    ofstream fout(outfile);
    fout << "day " << "hour" << "\t" << "temp" << "\t" << endl;

    double Total = 0.0, fmax = 0, fmin = 0;
    int count = 0, t = 0;
    string date, time, maxdate, mindate, junk;
    double temp;
    fin >> junk >> junk;

    
    // Conversion from Celsius to Fahrenheit
    while (fin >> date >> time >> temp)
    {
       

        double F = 0.0;
        // fin >> F;

        F = ((9.0/5.0)*temp)+32.0;
        Total += F;
        //cout << date << " " << time << " " << temp << endl;
        

        if(count == 0)
        {
            fmax = F;
            fmin = F;
            maxdate = date;
            mindate = date;
        }

        count++;

        //Define the parameters for a min and max and their corresponding date
        if(F > fmax)
        {
            fmax = F;
            maxdate = date;
        }

        if(F < fmin)
        {
            fmin = F;
            mindate = date;
        }
        
        t++;

        if (t > 24)
            t = 1;
        fout << date << "\t" << t << '\t' << F << endl;
    }

    cout << "file: " << file << endl;
    cout << "ave: " << (Total/count) << endl;
    cout << "min: " << fmin << " on " << mindate << endl;
    cout << "max: " << fmax << " on " << maxdate << endl;
    cout << "output in: " << outfile << endl;

    
    return 0;
}

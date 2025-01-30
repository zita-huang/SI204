/*******************
Filename: part1.cpp
Author: Zita Huang (m272898)
Lab04 Part 1
********************/
#include <iostream>
#include <fstream>
using namespace std;

    int main()
    {
        string file;
        cin >> file;

        ifstream fin(file);

        if(!fin)
        {
            cout << "Could not open file '" << file << "'" << endl;
            return 1;
        }

        double temp, count, Fsum;
        Fsum = 0.0;
        count = 0.0;

        string time;

        while (fin >> time >> temp)
        {  
            double Fah = ((9.0/5.0)*(temp))+32.0;

            Fsum = Fah + Fsum;
            count = count + 1.0;
        }
        cout << "file: " << file << endl;
        cout << "ave: " << double(Fsum/count) << endl;

        return 0;
    }
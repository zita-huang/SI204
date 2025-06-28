#include <iostream>
#include <fstream>
#include <iomanip>  // For formatting output
using namespace std;

int main()
{
    string file;
    cin >> file;  // Read filename from user

    ifstream fin(file);
    if (!fin)  // Check if file exists
    {
        cout << "Could not open file '" << file << "'" << endl;
        return 1;  // Indicate error
    }

    string time;
    double temp, sum = 0.0, count = 0.0;

    while (fin >> time >> temp)  // Read time and temperature
    {
        double Tf = ((9.0 / 5.0) * temp) + 32.0;  // Convert Celsius to Fahrenheit
        sum += Tf;
        count++;
    }

    if (count == 0)  // Check for empty file
    {
        cout << "No valid temperature data found." << endl;
        return 1;  // Indicate error
    }

    cout << "file: " << file << endl;
    cout << "ave: " << fixed << setprecision(4) << (sum / count) << endl;

    return 0;  // Indicate success
}



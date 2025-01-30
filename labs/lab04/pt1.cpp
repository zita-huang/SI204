#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string file;
    cin >> file;  // Input the filename

    ifstream fin(file);  // Open the file

    if (!fin)
    {
        cout << "Could not open file '" << file << "'" << endl;  // Error if file can't be opened
        return 1;
    }

    double temp, Fsum = 0.0;  // Fsum stores the sum of Fahrenheit values
    int count = 0;  // Count of valid temperatures

    string time;  // Variable to hold the time column (which we don't use)

    // Read each line from the file
    while (fin >> time >> temp)  // Read the time (ignored) and temp (used)
    {
        // Output the raw data for debugging purposes
        cout << "Raw data: " << time << " " << temp << endl;  // Print time and temp values

        // Convert Celsius to Fahrenheit
        double Fah = (9.0 / 5.0) * temp + 32.0;
        
        Fsum += Fah;  // Accumulate the Fahrenheit value
        count++;  // Increment the count for each valid temperature
    }

    // Check if we have read any valid temperatures
    if (count > 0)
    {
        // Compute and output the average Fahrenheit value
        cout << "File: " << file << endl;
        cout << "Average Fahrenheit: " << Fsum / count << endl;  // Calculate average
    }
    else
    {
        cout << "No valid data to process." << endl;  // If no valid data was processed
    }

    return 0;
}


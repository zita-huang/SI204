#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string inputFile, outputFile;
    cin >> inputFile >> outputFile;

    // Open input file
    ifstream fin(inputFile);
    if (!fin) {
        cout << "Could not open file '" << inputFile << "'" << endl;
        return 1;
    }

    // Open output file
    ofstream fout(outputFile);
    if (!fout) {
        cout << "Could not open output file '" << outputFile << "'" << endl;
        return 1;
    }

    // Write header to output file
    fout << "day\thour\ttemp" << endl;

    string time, temp;
    double celsius, fahrenheit;
    int hour;

    // Skip the header row of input file
    fin >> time >> temp;

    // Process each data row
    while (fin >> time >> temp) {
        // Check if the time string is valid (it should be at least 19 characters for "YYYY-MM-DD HH:MM:SS")
        if (time.length() >= 19) {
            // Convert temperature to Fahrenheit
            celsius = stod(temp);  // stod() converts string to double
            fahrenheit = (celsius * 9.0 / 5.0) + 32;  // Celsius to Fahrenheit conversion

            // Extract date and hour
            string date = time.substr(0, 10);  // Extract "YYYY-MM-DD"
            hour = stoi(time.substr(11, 2));   // Extract hour part "HH" from "HH:MM:SS"
            
            if (hour == 0) hour = 1;  // Convert "00" hour to "1"

            // Write the processed data to the output file
            fout << date << "\t" << hour << "\t" << fixed << setprecision(1) << fahrenheit << endl;
        } else {
            // If time string is shorter than expected, skip this row
            cerr << "Warning: Skipping row with invalid time format: " << time << endl;
        }
    }

    // Close files
    fin.close();
    fout.close();

    cout << "Output written to " << outputFile << endl;

    return 0;
}


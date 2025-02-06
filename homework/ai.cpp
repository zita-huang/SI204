#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string file;
    cout << "Filename: ";
    cin >> file;

    ifstream fin(file);
    
    if (!fin) {
        cout << "File not found!" << endl;
        return 1;
    }
    
    string name;
    int month, day, year;
    int adults = 0, children = 0;

    // Read the file line by line
    while (fin >> name) {
        // Read the date in MM/DD/YY format
        char slash1, slash2;  // To store '/' characters
        fin >> month >> slash1 >> day >> slash2 >> year;

        // Adjust year interpretation: Years 00-32 as 2000-2032, Years 33-99 as 1900-1999
        if (year < 19) {
            year += 2000;  // Treat years 00-32 as 2000-2032 (e.g., 01 becomes 2001)
        } else {
            year += 1900;  // Treat years 33-99 as 1900-1999 (e.g., 45 becomes 1945)
        }

        // Now compare the dates for the cutoff (September 27, 2000)
        bool isAdult = false;

        // Debugging output to see what date we are working with
        cout << "Checking: " << name << " - " << month << "/" << day << "/" << year << endl;

        // Check if the birthdate indicates an adult or a child
        if (year < 2000) {
            isAdult = true;  // Any birthdate before 2000 is an adult
        } else if (year == 2000) {
            if (month < 9 || (month == 9 && day <= 27)) {
                isAdult = true;  // September 27, 2000 cutoff
            }
        }

        // Output who is adult or child
        if (isAdult) {
            adults++;
            cout << name << " is an adult." << endl;
        } else {
            children++;
            cout << name << " is a child." << endl;
        }
    }

    cout << "Adults: " << adults << endl;
    cout << "Children: " << children << endl;
    
    return 0;
}



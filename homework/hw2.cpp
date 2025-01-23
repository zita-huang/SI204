#include <iostream>
using namespace std;

int main() {
    double a, b;
    char comma;
    string command;
    double num;

    // Input a and b
    cout << "Values for a and b? ";
    cin >> a >> comma >> b;

    // Input the command
    cout << "What do you want? ";
    cin.ignore();
    cin >> command;

    // Process commands
    if (command == "square") {
        char var;
        cin >> var; // Read which variable (a or b) to square
        if (var == 'a') a = a * a;
        else if (var == 'b') b = b * b;
    } else if (command == "add") {
        cin >> num >> command; // Read the number and target variable
        if (command == "to") {
            char var;
            cin >> var; // Read which variable (a or b) to add to
            if (var == 'a') a += num;
            else if (var == 'b') b += num;
        }
    }

    // Output the result
    cout << "a = " << a << " and b = " << b << endl;
    return 0;
}

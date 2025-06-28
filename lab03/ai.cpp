#include <iostream>
using namespace std;

int main() 
{
    char number1, number2, op, equal;
    int num1 = 0, num2 = 0, result;

    // Read first number type
    cin >> number1;

    // Convert binary or decimal input
    if (number1 == 'B') {
        char b1, b2, b3, b4;
        cin >> b1 >> b2 >> b3 >> b4;
        num1 = (b1 - '0') * 8 + (b2 - '0') * 4 + (b3 - '0') * 2 + (b4 - '0') * 1;
    } else {
        cin >> num1;
    }

    // Read operation
    cin >> op;

    if (op == '+') {
        cin >> number2;

        // Convert second binary or decimal input
        if (number2 == 'B') {
            char bit1, bit2, bit3, bit4;
            cin >> bit1 >> bit2 >> bit3 >> bit4;
            num2 = (bit1 - '0') * 8 + (bit2 - '0') * 4 + (bit3 - '0') * 2 + (bit4 - '0') * 1;
        } else {
            cin >> num2;
        }

        result = num1 + num2;
    } else {
        result = num1;
    }

    // Determine output type
    if (result < 16) {
        cout << "B" 
             << (result / 8) % 2 
             << (result / 4) % 2 
             << (result / 2) % 2 
             << (result / 1) % 2 
             << endl;
    } else {
        cout << "D" << result << endl;
    }

    return 0;
}

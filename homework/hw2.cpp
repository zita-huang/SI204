#include <iostream>
using namespace std;

int main() {
    int cookies, eaten, days = 0, piggiest = 0, totalEaten = 0;

    cout << "How many cookies? ";
    cin >> cookies;

    while (cookies > 0) {
        days++;
        cout << "Cookies eaten on day " << days << ": ";
        cin >> eaten;

        if (eaten > cookies) {
            cout << "Not enough cookies!" << endl;
            return 1;
        }

        cookies -= eaten;
        totalEaten += eaten;
        if (eaten > piggiest) piggiest = eaten;
    }

    cout << "You ate " << totalEaten << " cookies over " << days << " days." << endl;
    cout << "On your piggiest day you ate " << piggiest << " cookies." << endl;

    return 0;
}



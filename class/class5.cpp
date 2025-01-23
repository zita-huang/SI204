#include <iostream>
using namespace std;

    int main()
    {
        int a;
        cin >> a;

        if (a < 0)
        {
            a = a * -1;
            cout << "a was negative\n";
        }
        if (a % 2 == 0)
        {
            cout << "a is even\n" << endl;
        }
        else
        {
            cout << "a is odd\n" << endl;
        }

        return 0;
    }
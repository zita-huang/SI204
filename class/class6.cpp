#include <iostream>
using namespace std;

    int main()
    {
        int a;
        cout << &a << endl;

        {
            int b;
            cout << &b << endl;
        }

        int c;
        cout << &c << endl;
        
        return 0;
    }
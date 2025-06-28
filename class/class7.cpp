#include <iostream>
#include <cmath>
using namespace std;

    int main()
    {
        double n, sum;
        cin >> n;
        
        while (n > 0)
        {
            sum = sum + n;
            cin >> n;

        }

        cout << "sum is: " << sum << endl;

        return 0;
    }
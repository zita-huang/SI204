//Problem 3
#include<iostream>
using namespace std;
    int main()
    {
        int n;
        cout << "Give an odd number n (n>=3): ";
        cin >> n;

        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0 || j == n-1 || i == n/2)
                    cout << "#";
                else
                    cout << ".";
            }
            cout << endl;
        }

        return 0;
    }
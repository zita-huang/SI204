#include <iostream>
using namespace std;

    int main()
    {
        int kv;
        cout << "Enter key value: ";
        cin >> kv;

        cout << "Enter 4-letter message:";
        char c1, c2, c3, c4;
        cin >> c1 >> c2 >> c3 >> c4;

        int e1, e2, e3, e4;
        e1 = c1 - 'a';
        e2 = c2 -'a';
        e3 = c3 - 'a';
        e4 = c4 - 'a';

        int ec1, ec2, ec3, ec4;
        ec1 = (e1 + kv) %26;
        ec2 = (e2 + kv) %26;
        ec3 = (e3 + kv) %26;
        ec4 = (e4 + kv) %26;

        char w1, w2, w3, w4;
        w1 = 'a' + ec1;
        w2 = 'a' + ec2;
        w3 = 'a' + ec3;
        w4 = 'a' + ec4;



        cout << "Encrypted message is: " << w1 << w2 << w3 << w4 << endl;
        return 0;
    }
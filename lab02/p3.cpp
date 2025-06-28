/*********************
Filename: p3.cpp
Author: Zita Huang (m272898)
Lab 2: Part 3
*********************/
#include <iostream>
using namespace std;

    int main()
    {
        //Prompt user to enter in Permissions
        char u, g, o;
        cout << "Permissions: ";
        cin >> u >> g >> o;

        //Math to read out the first decimal character in binary(user)
        cout << endl;
        cout << "User: " << endl;
        bool u1, u2, u3;
        u1 = (u/1)%2;
        u2 = (u/2)%2;
        u3 = (u/(2*2))%2;
        cout << "read     " << u3 << endl;
        cout << "write    " << u2 << endl;
        cout << "execute  " << u1 << endl;

        //Math to read out the second decimal character in binary(group)
        cout << endl;
        cout << "Group: " << endl;
        bool g1, g2, g3;
        g1 = (g/1)%2;
        g2 = (g/2)%2;
        g3 = (g/(2*2))%2;
        cout << "read     " << g3 << endl;
        cout << "write    " << g2 << endl;
        cout << "execute  " << g1 << endl;

        //Math to read out the third decimal character in binary(other)
        cout << endl;
        cout << "Other: " << endl;
        bool o1, o2, o3;
        o1 = (o/1)%2;
        o2 = (o/2)%2;
        o3 = (o/(2*2))%2;
        cout << "read     " << o3 << endl;
        cout << "write    " << o2 << endl;
        cout << "execute  " << o1 << endl;


        return 0;
    }
/******************
Filename: part1.cpp
Author: Zita Huang (m272898)
Lab 3 Part 1
******************/
#include<iostream>
using namespace std;

    int main()
    {
        //The input for the coordinates
        double a, b, c, d, e, f;
        char p1, c1, p2, s1, p3, c2, p4, s2, p5, c3, p6;
        cin >> p1 >> a >> c1 >> d >> p2 >> p3 >> b >> c2 >> e >> p4 >> p5 >> c >> c3 >> f >> p6;

        //Math to compute the lengths for least and greatest point
        double x1;
        if (a<=b && a<=c)
            x1 = a;
        else if (b<=a && b<=c)
            x1 = b;
        else if (c<=a && c<=b)
            x1 = c;

        double x3;
        if (a>=b && a>=c)
            x3 = a;
        else if (b>=a && b>=c)
            x3 = b;
        else if (c>=a && c>=b)
            x3 = c;

        double y3;
        if (d<=e && d<=f)
            y3 = d;
        else if (e<=d && e<=f)
            y3 = e;
        else if (f<=d && f<=e)
            y3 = f;

        double y2;
        if (d>=e && d>=f)
            y2 = d;
        else if (e>=d && e>=f)
            y2 = e;
        else if (f>=d && f>=e)
            y2 = f; 

        //Math for drawing boundary box
        cout << x1 << " " << y3 << endl;
        cout << x1 << " " << y2 << endl;
        cout << x3 << " " << y2 << endl;
        cout << x3 << " " << y3 << endl;
        cout << x1 << " " << y3 << endl;

        //Space to divide the box by the triangle coordinates
        cout << endl;

        //Drawing the triangle
        cout << a << " " << d << endl;
        cout << b << " " << e << endl;
        cout << c << " " << f << endl;
        cout << a << " " << d << endl;

        return 0;
    }
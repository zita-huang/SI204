/*****************
File name: hw.cpp
Author: MIDN Zita Huang (m272898)
Homework 8
****************/
#include <iostream>
using namespace std;

    int main()
    {
        //Defining the variables
        int ck, sum, day, eaten, max;
        sum = 0;
        day = 0;
        max = 0;
        cout << "How many cookies? ";
        cin >> ck;

        //While loop for the cookies
        while (ck > 0)
        {
            //Math for days and input for number of cookies in jar
            day = 1 + day;
            cout << "Cookies eaten on day " << day << ": ";
            cin >> eaten;

            //If eaten is greater than cookies in the jar
            if (eaten > ck)
            {
               cout << "Not enough cookies!" << endl;
               return 0;
            }

            //Math to check the cookies to eaten to the total eaten
            ck = ck - eaten;
            sum = sum + eaten;

            //If statement to determine most cookies eatten in one day
            if(eaten > max )
            {
                max = eaten;
            }
            
        }  

        //Result
        cout << "You ate " << sum << " cookies over " << day << " days." << endl;
        cout << "On your piggiest day you ate " << max << " cookies." << endl;
       
        return 0;
    }
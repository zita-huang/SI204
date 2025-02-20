/************
Filename: p1.cpp
Author: MIDN Zita Huang (m272898)
Lab 6 Part 1
************/
#include <iostream>
#include <cstdlib>
using namespace std;
    
    int main()
    {
        int seed;
        cout << "Enter seed value: ";
        cin >> seed;
        srand(seed);
        
        int d1 = rolldie1(), d2 = rolldie2();
        if(d1 > 6 || d1 == 0)
        {
            cout << rand()%8 << endl;
        }
        else 
            cout << d1 << endl;

        if(d2 > 6 || d2 ==0)
            cout << rand()%8 << endl;
        else
            cout << d2 << endl;

        return 0;
    }

  int rolldie1()
  {
    int i = 0;
    while (i < 5)
    {
        cout << rand()%8 << endl;
    }
    return i;
  }
  
  int rolldie2()
  {
    int j = 0;
    while (j < 5)
    {
        cout << rand()%8 << endl;
    }

    return j;
  }
    
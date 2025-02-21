/**********
Filename: hw.cpp
Author: MIDN Zita Huang (m272898)
Homework 15
**********/
#include <iostream>
using namespace std;

//==========================================
// Give the prototype of firstfactor below
int firstfactor(int n);
//==========================================
// main function
int main()
{
  // Get integer n, n > 1, from user
  int n;
  cout << "Enter an integer larger than 1: ";
  cin >> n;

  // Print out factorization
  cout << "The factorization of " << n << " is ";
  while(n > 1)
  {
    // get & print next prime factor
    int f = firstfactor(n);
    cout << '(' << f << ')';
    n = n / f;
  }
  cout << endl;

  return 0;
}

//==========================================
// Define firstfactor below
int firstfactor(int n)
{
    //If divisble by 2, then output 2
    if(n % 2 == 0)
    {
        return 2;
    }

    //If not divisible by two then divide by the second smallest prime number
    for(int i = 3; i*i <= n; i+=2)
    {
        if(n % i == 0)
        {
            return i;
        }
    }

    return n;
}

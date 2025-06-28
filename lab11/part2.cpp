/*******
Filename: part2.cpp
Author: Zita Huang (m272898)
Lab 11 Part 2
*******/
#include <iostream>
#include <string>
using namespace std; 
#include "fractals.h"

int main()
{
  cout << "size: ";
  int n;
  cin >> n;

  cout << "Width-" << n << " Cantor row:" << endl;
  cantor_row(n); //changed so I can get the test cases for part 2,
                  //without interfering with part3
  cout << endl;

  return 0;
}
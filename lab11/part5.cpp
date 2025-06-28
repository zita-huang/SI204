/*******
Filename: part5.cpp
Author: Zita Huang (m272898)
Lab 11 Part 5
*******/
#include <iostream>
using namespace std; 
#include "fractals.h"

int main()
{
  cout << "size: ";
  int n;
  cin >> n;

  cout << "Width-" << n << " Sierpinski carpet:" << endl;

  repeat_carpet_row(n, 0); 
  return 0;
}

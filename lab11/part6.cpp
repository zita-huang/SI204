/*******
Filename: part6.cpp
Author: Zita Huang (m272898)
Lab 11 Part 6
*******/
#include <iostream>
using namespace std;
#include "fractals.h"

int main()
{
  cout << "size: ";
  int n;
  cin >> n;

  cout << "Height-" << n << " Sierpinski triangle:" << endl;
  repeat_triangle_row(n, 0); 

  return 0;
}

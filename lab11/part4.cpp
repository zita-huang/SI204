/*******
Filename: part4.cpp
Author: Zita Huang (m272898)
Lab 11 Part 4
*******/
#include <iostream>
using namespace std;
#include "fractals.h"

int main()
{
  int n;
  cout << "size: ";
  cin >> n;

  cout << "Width-" << n << " Cantor set:" << endl;
  repeat_cantor_row(n, 1);

  return 0;
}
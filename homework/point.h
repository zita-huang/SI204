#pragma once
#include <iostream>
using namespace std;

//prototype and struct defintion for point.h
struct point
{
  double x, y;
};
istream& operator >> (istream& in, point& p);
ostream& operator << (ostream& os, point p);
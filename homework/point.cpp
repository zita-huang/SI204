#include <iostream>
using namespace std;
#include "point.h"

//Defintions for point.h
istream& operator >> (istream& is, point &p)
{
  char c;
  return is >> c >> p.x >> c >> p.y >> c;
}

ostream& operator << (ostream& os, point p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}
#include <iostream>
using namespace std;
#include "point.h"
#include "datum.h"
#include "hhmmss.h"

//defintions for datum.h
istream& operator >> (istream& is, datum& D)
{
  char c;
  return is >> c >> D.time >> c >> D.position >> c; 
}
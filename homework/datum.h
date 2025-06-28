#pragma once
#include <iostream>
#include "point.h"
#include "hhmmss.h"
using namespace std;

//prototype and struct defintion for datum.h
struct datum
{
  point position;
  hhmmss time;
};
istream& operator >> (istream& is, datum& D);
#pragma once
#include <iostream>
using namespace std;

//prototype and struct defintion for hhmmss.h
struct hhmmss
{
  int h,m,s;
};
istream& operator >> (istream& is, hhmmss& T);
bool operator < (hhmmss a, hhmmss b);
/**********
Filename: p1.cpp
Author: Zita Huang (m272898)
Lab 10 Part 1
**********/
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "easycurses.h"
using namespace std;
int main() {
  // Initialize ncurses
  startCurses();

  // Draw 4 digit characters to the terminal screen.
  drawCharAndRefresh('A', 0, 0);
  usleep(800000);
  
  drawCharAndRefresh('B', 20, 30);
  cerr << "Printed a B!" << endl;
  usleep(800000);

  drawCharAndRefresh('C', 20, 31);
  usleep(800000);

  drawCharAndRefresh('D', 15, 50);
  
  // Loop forever until user enters 'q'
  char c = ' ';
  while ( c != 'q' )
  {
    c = inputChar();
  }

  // Close ncurses
  endCurses();
  
  return 0;
}
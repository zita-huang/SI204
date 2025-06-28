/*********
Filename: hw.cpp
Author: Zita Huang (m272898)
Homework 33
*********/
#include <iostream>
#include "ll.h"
using namespace std;

int main()
{
  Node* L = NULL;

  // read the numbers into list L
  int d;
  while( cin >> d && d > 0)
    L = add2back(d, L);

  // handle the commands
  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "enter" )
    {
      // enter d after x
      string s;
      int x;
      cin >> d >> s >> x;
      enter_after(d, x, L); 
    }
    else if ( cmd == "remove" )
    {
      // remove d
      cin >> d;
      L = remove(d, L); 
    }
    else if ( cmd == "print" )
    {
      // print L
      print(L);
      cout << endl;
    }
    else if ( cmd == "rprint" )
    {
      reverse_print(L);
      cout << endl;
    }
    else if ( cmd == "sum" )
    {
      cout << sum(L) << endl;
    } 
  }

  // delete the list 
  deletelist(L);
  return 0;
}
/*********
Filename: hw.cpp
Author: Zita Huang (m272898)
Homework 30
*********/
#include <iostream>
#include <string>
#include "hw32.h"
using namespace std;

  int main(){
    Node* J = NULL;
    string word;
    cout << "Enter words followed by END:" << endl;

    //read in user input for the string of words
    while(cin >> word && word != "END"){
      J = add2front(J, word);
    }

    //take in user input
    cout << "What letter? ";
    char letter;
    cin >> letter;

    printReverse(J, letter); //call reverse function for output

    deleteList(J); //delete the list for valgrind
    return 0;
  }
/**********
Filename: part1.cpp
Author: Zita Huang (m272898)
Lab 12 Part 1
**********/
#include <iostream>
#include <fstream>
using namespace std;
#include "library.h"

    int main(){
        //get user input
        string filename;
        cout << "Input file is: ";
        cin >> filename;
        ifstream fin(filename);
        if(!fin){
            cout << "Error! File '" << filename << "' not found!"<< endl;
            return 1;
        }

        //create node for head
        Node* head = NULL;
        Pair p;
        char ch;
        //read in the file contents
        while(fin >> ch >> p.word >> p.num >> ch){
            head = add2front(head,p);
        }

        //math and count
        int count = countList(head);
        cout << "Count is " << count << endl;
        printList(head); //call function to print
        cout << endl;
        free(head); //free memory
        return 0;
        
    }
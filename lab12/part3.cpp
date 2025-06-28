/***********
Filename: part3.cpp
Author: Zita Huang (m272898)
Lab 12 Part 3
***********/
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

        //create a node for head
        Node* head = NULL;
        Pair p;
        char ch;
        //read in the file contents
        while(fin >> ch >> p.word >> p.num >> ch){
            head = add2front(head,p);
        }

        //create new node and set it equal to head
        Node* current = head;
        //output
        while(current != 0){
            cout << "The current node: (" << current->data.word
                 << " " << current->data.num << ")" << endl;
            cout << "Nodes before the current: ";
            printBefore(head, current); //print out node currently on
            cout << "#nodes after the current: " << countAfter(current) << endl;

            char response;
            cout << "[a]ccept or [r]eject: ";
            cin >> response;

            current = current->next;
            cout << endl;
        }

        cout << "List is: ";
        printWord(head); //print out all the words
        cout << "Score is: " << totalScore(head) << endl; //show score
        free(head); //free memory
        return 0;
    }
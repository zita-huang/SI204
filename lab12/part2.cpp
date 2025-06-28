/***********
Filename: part2.cpp
Author: Zita Huang (m272898)
Lab 12 Part 2
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

        //create node for head
        Node* head = NULL;
        Pair p;
        char ch;
        //read in the file contents
        while(fin >> ch >> p.word >> p.num >> ch){
            head = add2front(head,p);
        }

        //create a new node and make it the same as head
        Node* current = head;
        //output
        while(current != 0){
            cout << "The current node: (" << current->data.word
                 << " " << current->data.num << ")" << endl;
            cout << "Nodes before the current: ";
            printBefore(head, current); //print the node before current
            cout << "#nodes after the current: " << countAfter(current) << endl;

            char response;
            cout << "[a]ccept or [r]eject: ";
            cin >> response;

            current = current->next;
            cout << endl;
        }

        cout << "List is: ";
        printList(head); //print all the words
        cout << endl;
        free(head); //free memory
        return 0;
    }
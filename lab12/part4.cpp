/*********
Filename: part4.cpp
Author: Zita Huang (m272898)
Lab 12 Part 4
*********/
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
        //read in file contents
        while(fin >> ch >> p.word >> p.num >> ch){
            head = add2front(head,p);
        }

        Node* sentence = NULL; //make a sentence node

        Node* current = head; //set current equal to head
        //output
        while(current != 0){
            cout << "The current node: (" << current->data.word
                 << " " << current->data.num << ")" << endl;
            cout << "Sentence you made so far: ";
            printSentence(sentence); //print out the choosen node(s)
            cout << "#words left: " << words(current) << endl; //word count

            char response;
            cout << "[a]ccept or [r]eject: ";
            cin >> response;
            if(response == 'a'){
                sentence = add2end(sentence, current->data); //add to the end
            }

            current = current->next;
            cout << endl;
        }

        cout << "Sentence is: ";
        printSentence(sentence); //print out only choosen nodes
        cout << "Score is: " << sentenceScore(sentence) << endl; //print out score
        free(head); //free memory
        free(sentence); //free memory
        return 0;
    }
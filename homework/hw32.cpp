#include <iostream>
using namespace std;
#include "hw32.h"

    //function for adding lists
    Node* add2front(Node* J, string word){
        Node* newNode = new Node;
        newNode->word = word; //assign the word node
        newNode->next = NULL; //assign the next node

    //condition for returning the code
        if(J == NULL){
            return newNode;
        }
        Node* temp = J;
        //loop if the next node is empty
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        return J;
    }
    
    //reverse function
    void printReverse(Node* node, char letter){
        if(node == NULL){
            return;
        }
        printReverse(node->next, letter);

        if(node->word[0] == letter){
            cout << node->word << endl;
        }
    }

    //delete the list function
    void deleteList(Node* node){
        while(node != NULL){
            Node* next = node->next;
            delete node;
            node = next;
        }
    }

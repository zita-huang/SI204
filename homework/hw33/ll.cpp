#include <iostream>
using namespace std;
#include "ll.h"

Node* add2back(int d, Node* L){
    Node* newNode = new Node; //create a node
    newNode->data = d;
    newNode->next = NULL;

    if(!L){
        return newNode;
    }

    Node* b = L; //create a temp node
    while(b->next){
        b = b->next;
    }
    b->next = newNode; //set it equal to the node made above
    return L;
}

void print(Node* L){
    while(L){
        cout << L->data;
        if(L->next){
            cout << " "; //formatting
        }
        L = L->next; //have L be the next in the Node
    }
}

void reverse_print(Node* L){
    if(!L)
        return;
    reverse_print(L->next);
    cout << L->data; //print out the output after reversing
    if(L->next)
        cout << " "; //formatting
}

int sum(Node* L){
    if(!L)
        return 0;
    return L->data + sum(L->next);
}

void enter_after(int d, int x, Node* L){
    while(L){
        if(L->data == x){
            Node* newNode = new Node;
            newNode->data = d; //set the data to the inputted integar
            newNode->next = L->next; //make the next be equal to the next of Node L
            L->next = newNode;
            return;
        }
        L = L->next;
    }
}

Node* remove(int d, Node* L){
    if(!L)
        return NULL;
    if(L->data == d){
        Node* temp = L->next; //create a temporary node
        delete L; //free the memory of L
        return remove(d, temp);
    }
    L->next = remove(d, L->next);
    return L;
}

//free the memory blocks
void deletelist(Node* L){
    while(L){
        Node* next = L->next;
        delete L;
        L = next;
    }
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "library.h"

Node* add2front(Node* head, Pair p){
    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = head;
    head = newNode;

    return newNode;
}

Node* add2end(Node* head, Pair p){
    Node* newNode = new Node;
    newNode->data = p;
    newNode->next = NULL;

    if(head == NULL){
        return newNode;
    }

    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node* head){
    Node* current = head;
    while(current != NULL){
        cout << "(" << current->data.word << " " 
             << current->data.num << ")";
        current = current->next;
    }
}

int countList(Node* head){
    int count = 0;
    while(head != 0){
        count++;
        head = head->next;
    }
    return count;
}

void printBefore(Node* head, Node* current){
    while(head != current){
        cout << "(" << head->data.word << " "
             << head->data.num << ")";
        head = head->next;
    }
    if(current != 0){
        cout << endl;
    }
}

int countAfter(Node* current){
    int count  = 0;
    current = current->next;
    while(current != 0){
        count++;
        current = current->next;
    }
    return count;
}

void printWord(Node* head){
    while(head != NULL){
        cout << head->data.word << " ";
        head = head->next;
    }
    cout << endl;
}

int totalScore(Node* head){
    int sum = 0;
    while(head != NULL){
        sum += head->data.num;
        head = head->next;
    }
    return sum;
}

void printSentence(Node* head){
    while(head != NULL){
        cout << head-> data.word << " ";
        head = head->next;
    }
    cout << endl;
}

int words(Node* current){
    int count = 0;
    current = current->next;
    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

int sentenceScore(Node* head){
    int sum = 0;
    while(head != NULL){
        sum += head->data.num;
        head = head->next;
    }
    return sum;
}

void free(Node* head){
    Node* current = head;
    while(current != NULL){
            Node* temp = current;
            current = current->next;
            delete temp;
        }
}
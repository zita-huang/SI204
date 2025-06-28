#include <iostream>
#include <string>
using namespace std;

struct Pair{
    string word;
    int num;
};

struct Node{
    Pair data;
    Node* next;
};

Node* add2front(Node* head, Pair p);
Node* add2end(Node* head, Pair p);
void printList(Node* head);
int countList(Node* head);
void printBefore(Node* head, Node* current);
int countAfter(Node* current);
void printWord(Node* head);
int totalScore(Node* head);
void printSentence(Node* head);
int words(Node* current);
int sentenceScore(Node* head);
void free(Node* head);
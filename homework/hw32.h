#include <string>
using namespace std;

    struct Node{
        string word;
        Node* next;
    };

Node* add2front(Node* head, string word);
void printReverse(Node* node, char letter);
void deleteList(Node* node);
/**********
Filename: p5.cpp
Author: Zita Huang(m27289)
Project 2 Part 5
**********/
//Recieved help from MGSP leader
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int maxcards = 52;
int deck[maxcards], player[maxcards], dealer[maxcards];
int decksize = maxcards, playersize = 0, dealersize = 0;

string getCardString(int card) {
    // Unicode suit symbols
    string clubs = "\u2663"; 
    string diamonds = "\u2666"; 
    string hearts = "\u2665"; 
    string spades = "\u2660";  

    //Correct suit ordering
    string suits[] = {"", clubs, diamonds, hearts, spades}; // Spades, Hearts, Diamonds, Clubs
    string faces[] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    int suit = card / 100;
    int face = card % 100;

   // cout << "suit num is : " << suit << endl << " and face num is " << face << endl;

    string faceStr = faces[face];

    // Add space for single-digit values (except 10)
    if (faceStr != "10") {
        faceStr = " " + faceStr;
    }

    return faceStr + suits[suit];
}

//initialize deck function
void initializedeck() {
    playersize = 0;
    dealersize = 0;
    decksize = maxcards;
    int index = 0;

    //math for suit and face index value
    for (int suit = 1; suit <= 4; suit++) {  
        for (int face = 2; face <= 14; face++) {  
            deck[index++] = suit * 100 + face;
        }
    }
}

//function for print vertical hands
void printverticalhands() {
    int maxSize = max(playersize, dealersize);

    bool dealerMoreThanPlayer = playersize < dealersize;

    cout << "Player Dealer" << endl;

    //for loop for the print out
    for (int i = 0; i < maxSize; i++) {
        cout << "| ";
        //if statement for the correct array print
        if (i < playersize - 1){ 
            cout << getCardString(player[i]);
        }
        else if(i == playersize - 1)
            cout << getCardString(player[i]);
        else cout << "   ";
        cout << "  | ";
        if (i < dealersize - 1) cout << getCardString(dealer[i]);
        else if(i == dealersize - 1)
            cout << getCardString(dealer[i]);
        else cout << "   ";
        cout << " |\n";
        
        
    }
    cout << "\n";
}

//deal function
void deal(int* hand, bool isPlayer) {
    if (decksize > 0) {
        //assign the dealing to either player or dealer
        int card = deck[0];
        if (isPlayer) {
            player[playersize++] = card;
        } else {
            dealer[dealersize++] = card;
        }
        
        for (int i = 0; i < decksize - 1; i++) {
            deck[i] = deck[i + 1];
        }
        decksize--;
    }
}

//shuffle deck function
void shuffleDeck() {
    for (int i = 0; i < decksize; i++) {
        int j = rand() % decksize;
        swap(deck[i], deck[j]);
    }
}

int main() {
    int seed;
    cout << "Seed: ";
    cin >> seed;
    srand(seed);
    
    initializedeck();
    shuffleDeck();
    cout << "\n";

    deal(player, true);
    deal(dealer, false);
    deal(player, true);
    deal(dealer, false);

    printverticalhands();

    //for loop to end at 3 rounds
    for (int round = 1; round <= 3; round++) {
        cout << "Round " << round << " Player's turn\n";
        string choice;
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        cout << "\n";
        if (choice == "h") deal(player, true);
        printverticalhands();
        cout << "Round " << round << " Dealer's turn\n";
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        if (choice == "h") deal(dealer, false);
        printverticalhands();
    }
    return 0;
}

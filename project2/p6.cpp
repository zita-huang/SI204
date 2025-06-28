/**********
Filename: p5.cpp
Author: Zita Huang(m27289)
Project 2 Part 6
**********/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int maxcards = 52;
int deck[maxcards], player[maxcards], dealer[maxcards];
int decksize = maxcards, playersize = 0, dealersize = 0;

//fancy print out function
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

    for (int suit = 1; suit <= 4; suit++) {  
        for (int face = 2; face <= 14; face++) {  
            deck[index++] = suit * 100 + face;
        }
    }
}

//function to calculate score
int calculateScore(int hand[], int size) {
    int total = 0, aces = 0;
    for (int i = 0; i < size; i++) {
        int face = hand[i] % 100;
        if (face >= 11 && face <= 13) total += 10;
        else if (face == 14) { total += 1; aces++; }
        else total += face;
    }
    if (aces > 0 && total <= 11) total += 10;
    return total;
}

//print vertical hands function
void printverticalhands() {
    int maxSize = max(playersize, dealersize);

    bool dealerMoreThanPlayer = playersize < dealersize;

    cout << "Player Dealer" << endl;

    //for loop to get the deck printed out correctly
    for (int i = 0; i < maxSize; i++) {
        cout << "| ";
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
    //print out the calculations from the calculation function
    cout << "Player " << calculateScore(player, playersize) << ", Dealer " 
         << calculateScore(dealer, dealersize) << "\n";
}

//deal function
void deal(int* hand, bool isPlayer) {
    //if statement for dealing cards to dealer/player
    if (decksize > 0) {
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
    bool playerStand = false, dealerStand = false;
    int round = 1; //count the rounds

    //while loop for infinite number of loops until stopped
    while(!(playerStand && dealerStand)) {
        cout << "Round " << round << " Player's turn\n";
        string choice;
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        cout << "\n";
        
        if (choice == "h"){ 
            deal(player, true);
            playerStand = false;
        }
        else{
            playerStand = true;
        }
        printverticalhands();
        
        if(playerStand && dealerStand)
            break;

        cout << "Round " << round << " Dealer's turn\n";
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        if (choice == "h"){ 
            deal(dealer, false);
            dealerStand = false;
        }
        else{
            dealerStand = true;
        }

        printverticalhands();
        round++;
    }
    return 0;
}
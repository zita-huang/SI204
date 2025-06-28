/************
Filename: p1.cpp
Author: Zita Huang(m272898)
Project 2 Part 1
************/
#include <iostream>
#include <string>
using namespace std;

    //create functions for each command
    int maxcards = 52; //number of cards in a deck
    int deck[52];
    int player[52];
    int dealer[52];
    int decksize = 52;
    int playersize = 0;
    int dealersize = 0;

    //initialize the deck
    void initializedeck() {
        int index = 0;
        for (int suit = 1; suit <= 4; suit++) {
            for (int face = 2; face <= 14; face++) {
                //math to determine value of each card
                deck[index++] = face + 100 * suit;
            }
        }
    }

    //create an array for the cards
    void printarray(int* array, int size) {
        cout << "[";
        for (int i = 0; i < size; i++) {
            cout << array[i];
            if (i < size - 1) {
                cout << " ";
            }
        }
        cout << "]\n";
    }

    //print deck function, output the array of the deck
    void printdeck() {
        printarray(deck, decksize);
    }

    //print player function, output the player array of the deck
    void printplayer() {
        printarray(player, playersize);
    }

    //dealer function, print the deck array for dealer
    void printdealer() {
        printarray(dealer, dealersize);
    }

    //deal function, print the deck array
    void deal(int* hand, int handindex) {
        //if condition for the handsize of the deck
        if (decksize > 0) {
            hand[handindex] = deck[0];
            if (hand == player) {
                playersize++;
            } else {
                dealersize++;
            }
            decksize--;
            //for loop for the deck array count
            for (int i = 0; i < decksize; i++) {
                deck[i] = deck[i + 1];
            }
        }
    }

    //dealer-player function, print out the array of the handisze of the deck
    void dealplayer() {
        deal(player, playersize);
    }

    //dealer-dealer function, print out the array of the handsize of dealer to dealer
    void dealdealer() {
        deal(dealer, dealersize);
    }

    int main() {
        initializedeck();

        //get user input on command
        string cmd;
        while (true) {
            cout << ">  ";
            cin >> cmd;
            //if condition for printing deck command
            if (cmd == "print-deck") {
                printdeck();
            } 
            //if condition for the print-p command
            else if (cmd == "print-p") {
                printplayer();
            } 
            //if condition for the print-d command
            else if (cmd == "print-d") {
                printdealer();
            } 
            //if condition for the deal-p command
            else if (cmd == "deal-p") {
                dealplayer();
            } 
            //if condition for the deal-d command
            else if (cmd == "deal-d") {
                dealdealer();
            } 
            //exit condition for the quit command
            else if (cmd == "quit") {
                return 1;
            }
        }
        return 0;
    }

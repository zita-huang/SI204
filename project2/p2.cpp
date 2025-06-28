/************
Filename: p2.cpp
Author: Zita Huang(m272898)
Project 2 Part 2
************/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

    //create functions for each command
    int maxcards = 52; //Number of cards in a deck
    int deck[52], player[52], dealer[52];
    int decksize = 52, playersize = 0, dealersize = 0;

    //initialize the deck
    void initializedeck() {
        playersize = 0;
        dealersize = 0;
        decksize = maxcards;
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
    void deal(int* hand, bool isPlayer) {
        //if condition for the handsize of the deck
        if (decksize > 0) {
            if (isPlayer) {
                player[playersize] = deck[0];
                playersize++;
            } else {
                dealer[dealersize] = deck[0];
                dealersize++;
            }

            //for loop for the deck array count
            for (int i = 0; i < decksize - 1; i++) {
                deck[i] = deck[i + 1];
            }
            decksize--;
        }
    }

    //dealer-player function, print out the array of the handisze of the deck
    void dealplayer() {
        deal(player, true);
    }

    //dealer-dealer function, print out the array of the handsize of dealer to dealer
    void dealdealer() {
        deal(dealer, false);
    }

    //Shuffle the deck
    void shuffleDeck() {
        if (decksize != maxcards) {
            cout << "Error: Not a full deck" << endl;
            return;
        }
        for (int i = 0; i < 52; i++) {
            int j = rand() % 52;
            swap(deck[i], deck[j]);
        }
    }

    //Reset the deck and hands
    void reset() {
        initializedeck();
    }

    int main() {
        int seed;
        cout << "Seed: ";
        cin >> seed;
        srand(seed);
        initializedeck();

        //get user input on command
        string cmd;
        while (true) {
            cout << "> ";
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
            //if condition for the shuffle-deck
            else if (cmd == "shuffle-deck") {
                shuffleDeck();
            }
            //if condition for the reset command
            else if (cmd == "reset") {
                reset();
            }
            //exit condition for the quit command
            else if (cmd == "quit") {
                return 0;
            }
        }
    }



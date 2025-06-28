/*********
Filename: p4.cpp
Author: Zita Huang (m272898)
Project 2 Part 4
*********/
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

    //print the hands of player and dealer function, vertical
    void printverticalhands() {
        int maxSize = max(playersize, dealersize);
        cout << " Player  Dealer\n";
        for (int i = 0; i < maxSize; i++) {
            cout << "| ";
            if (i < playersize) cout << player[i];
            else cout << "   ";
            cout << "  | ";
            if (i < dealersize) cout << dealer[i];
            else cout << "   ";
            cout << " |\n";
        }
    }

    //deal function, print the deck array
    void deal(int* hand, bool isPlayer) {
        if (decksize > 0) {
            if (isPlayer) {
                player[playersize++] = deck[0];
            } else {
                dealer[dealersize++] = deck[0];
            }
            for (int i = 0; i < decksize - 1; i++) {
                deck[i] = deck[i + 1];
            }
            decksize--;
        }
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
        shuffleDeck();
        printdeck();
        cout << "\n";
        
        // Deal two cards to both player and dealer
        //show the cards to the player and dealer
        deal(player, true);
        deal(dealer, false);
        deal(player, true);
        deal(dealer, false);

        printverticalhands();

        // Loop for three rounds
        for (int round = 1; round <= 3; round++) {
            //prompt player
            cout << "Round " << round << " Player's turn\n";
            string choice;
            cout << "hit or stand ? [h/s] ";
            cin >> choice;
            
            //If statement hit to player
            if (choice == "h") deal(player, true);
            //print out new hand to player
            printverticalhands();
            
            //prompt dealer
            cout << "Round " << round << " Dealer's turn\n";
            cout << "hit or stand ? [h/s] ";
            cin >> choice;
            
            //if statement for hit to dealer
            if (choice == "h") deal(dealer, false);
            printverticalhands();
        }
        return 0;
    }

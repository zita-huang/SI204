#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
using namespace std;

const int maxcards = 52;
int deck[maxcards], player[maxcards], dealer[maxcards];
int decksize = maxcards, playersize = 0, dealersize = 0;

string getCardString(int card, bool hide = false) {
    if (hide) return " **";
    string suits[] = {"", "♣", "♦", "♥", "♠"};
    string faces[] = {"", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int suit = card / 100;
    int face = card % 100;
    string faceStr = faces[face];
    if (faceStr != "10") faceStr = " " + faceStr;
    return faceStr + suits[suit];
}

void initializedeck() {
    playersize = dealersize = 0;
    decksize = maxcards;
    int index = 0;
    for (int suit = 1; suit <= 4; suit++)
        for (int face = 2; face <= 14; face++)
            deck[index++] = suit * 100 + face;
}

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

void printverticalhands(bool revealDealer = false) {
    cout << "Player Dealer" << endl;
    for (int i = 0; i < max(playersize, dealersize); i++) {
        cout << "| ";
        if (i < playersize) cout << getCardString(player[i]);
        else cout << "   ";
        cout << "  | ";
        if (i < dealersize) cout << getCardString(dealer[i], !revealDealer && i == 0);
        else cout << "   ";
        cout << " |" << endl;
    }
    cout << endl;
}

void deal(int* hand, bool isPlayer) {
    if (decksize > 0) {
        int card = deck[0];
        if (isPlayer) player[playersize++] = card;
        else dealer[dealersize++] = card;
        for (int i = 0; i < decksize - 1; i++) deck[i] = deck[i + 1];
        decksize--;
    }
}

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

    printverticalhands(true);
    bool playerStand = false, dealerStand = false;
    int round = 1;

    while (!(playerStand && dealerStand)) {
        cout << "\nRound " << round << " Player's turn\n";
        string choice;
        cout << "hit or stand? [h/s] ";
        cin >> choice;
        cout << "hit or stand? [h/s] " << choice << "\n";
        
        if (choice == "h") {
            deal(player, true);
            playerStand = false;
        } else {
            playerStand = true;
        }
        printverticalhands(true);
        
        if (calculateScore(player, playersize) > 21) {
            cout << "\nPlayer busts, dealer wins\n";
            return 0;
        }
        
        if (playerStand && dealerStand) break;

        cout << "\nRound " << round << " Dealer's turn\n";
        sleep(1);
        
        if (calculateScore(dealer, dealersize) < 17) {
            cout << "hit or stand? [h/s] h\n";
            deal(dealer, false);
            dealerStand = false;
        } else {
            cout << "hit or stand? [h/s] s\n";
            dealerStand = true;
        }
        printverticalhands(true);
        
        if (calculateScore(dealer, dealersize) > 21) {
            cout << "\nDealer busts, player wins\n";
            return 0;
        }
        
        round++;
    }

    cout << "\n";
    printverticalhands(false);
    
    int playerScore = calculateScore(player, playersize);
    int dealerScore = calculateScore(dealer, dealersize);
    
    if (playerScore > dealerScore) cout << "\nPlayer wins\n";
    else if (dealerScore > playerScore) cout << "\nDealer wins\n";
    else {
        cout << "\nIt's a tie! Restarting game...\n";
        main();
    }
    return 0;
}

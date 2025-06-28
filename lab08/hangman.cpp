/************
Filename: lab08.cpp
Author: Zita Huang (m272898)
Lab 08 Part 1
************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function prototypes
void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);
bool isInWord(char c, string word);

int main() {
    cout << "Welcome to hangman!" << endl;
    cout << "Enter a seed value: ";
    
    //Random generation of word from seed value
    int seed;
    cin >> seed;
    srand(seed);
    int n = rand() % 1466;

    //Open the word file
    ifstream fin("words07.txt");
    if (!fin) {
        cout << "Error: Could not open words07.txt" << endl;
        return 1;
    }

    //Read in the word from the file
    string word;
    for (int i = 0; i <= n && fin >> word; i++);

    //Initialize game variables
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int guessesLeft = 8;
    string shadow = mkShadowString(word);

    //Main part of the game
    while (guessesLeft > 0 && shadow != word) {
        //Display the status of the game
        cout << "Wrong guesses remaining: " << guessesLeft << "\t" << alphabet << endl;
        printSpaced(shadow);
        cout << endl;
        cout << ": ";

        //Ger user guess
        char guess;
        cin >> guess;

        //Check if the guess was right
        if (isInWord(guess, word)) {
            shadow = uncover(word, shadow, guess);
        } else {
            guessesLeft--;
            cout << "There were no " << guess << "'s!" << endl;
        }
        //cross out guessed words in the alphabet by updating it
        alphabet = crossOut(guess, alphabet);
    }

    //Game result
    if (shadow == word) {
        cout << "You win!!!! The word was " << word << endl;
    } else {
        cout << "You lose!!!! The word was " << word << endl;
    }

    return 0;
}

// Function to check if a character exists in the word
bool isInWord(char c, string word) {
    //Creates a range for the for loop
    //going through each character within the word and assigning it a char
    for (char letter : word) {
        if (letter == c) {
            return true;
        }
    }
    return false;
}

//Function for the printSpaced
void printSpaced(string s){
    //read in the length of the string
    for(int i = 0; i < s.length(); i++){
        //if condition to print out spaces in between each character of the string
        if(i > 0){
            cout << " ";
        }
        //print out the string with spaces in between
        cout << s[i];
    }
}

//function for mkShadowString
string mkShadowString(string s){
    //return "_", the same string length as s
    return string(s.length(), '_');
}

//function for uncover
string uncover(string original, string covered, char c){
    //read in the length of the string original
    for(int i = 0; i < original.length(); i++){
        //if condition for the uncover
        if(original[i] == c){
            //if the same character is identified within the original string
            //then the covered string will become the c
            //revealling the letter c
            covered[i] = c;
        }
    }
    return covered;
}

//function for crossOut
string crossOut(char c, string s){
    //read in the length of the string s
    for(int i = 0; i < s.length(); i++){
        //if condition for the cross out
        if(s[i] == c || //if any of the characters in s is equal to c
        (c >= 'a' && c <= 'z' && s[i] == c + 32) || //if the c character is lowercased, equal to any character in s
        (c >= 'A' && c <= 'Z' && s[i] == c - 32)){ //if the c character is capitalized, equal to any character in s
            s[i] = '*'; //use the * as a cross out 
        }
    }
    return s;
}

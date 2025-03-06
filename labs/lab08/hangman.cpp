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

//given functions with prototypes
void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

//main function
int main()
{
    cout << "Welcome to hangman!" << endl;
    
    //Have user put in a seed value
    int seed;
    cout << "Enter seed value: ";
    cin >> seed;
    srand(seed);
    int n = rand() % 1466;

    return 0;
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
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

//given int main()
int main()
{
  cout << "Testing printSpaced..." << endl;
  cout << "["; 
  printSpaced("wash"); 
  cout << "]" << endl;

  cout << "["; 
  printSpaced("HelloWorld!"); 
  cout << "]" << endl;

  

  cout << endl << "Testing mkShadowString..." << endl;
  string s1 = "food";
  string s2 = mkShadowString(s1);
  cout << "original: " << s1 << endl;
  cout << "  shadow: " << s2 << endl;
  string s3 = "require";
  string s4 = mkShadowString(s3);
  cout << "original: " << s3 << endl;
  cout << "  shadow: " << s4 << endl;

     
  cout << endl << "Testing uncover..." << endl;
  string u1 = "housepet";
  string u2 = "________";
  cout << u1 << endl << u2 << endl;
  
  string u3 = uncover(u1,u2,'e');
  if( u2 == u3 )
    cout << u3 << " there were not e's!"  << endl;
  else
    cout << u3 << " there were e's!"  << endl;
  u2 = u3;
 
  u3 = uncover(u1,u2,'q');
  if( u2 == u3 )
    cout << u3 << " there were not q's!"  << endl;
  else
    cout << u3 << " there were q's!"  << endl;

  cout << endl << "Testing crossOut..." << endl;
  string t1 = "Go get good food!";
  cout << t1 << endl;
  t1 = crossOut('o',t1);
  cout << t1 << endl;
  t1 = crossOut('g',t1);
  cout << t1 << endl;
   
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
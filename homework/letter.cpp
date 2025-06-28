#include <iostream>
#include <fstream>
using namespace std;
#include "letter.h"

    Letter loadLetter(ifstream& fin){
        Letter letter;
        //for loop for the row
        for(int i = 0; i < 4; i++){
            //for loop for the colums\ns
            for(int j = 0; j < 7; j++){
                char ch;
                fin.get(ch); //use to character from alphabet.txt
                while(ch == '\n' || ch == '\r'){
                    fin.get(ch);
                }
                //assign the array to ch
                letter.A[i][j] = ch;
            }
        }
        return letter;
    }

    void drawLetter(Letter* letters, char c){
        int type;
        type = c - 'A';//ensure that the entered word is captialized
        cout << endl;
        //for loop to read out the contents placed into the array
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 7; j++){
                cout << letters[type].A[i][j];
            }
            cout << endl;
        }
    }
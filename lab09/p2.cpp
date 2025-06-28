/**********
Filename: p2.cpp
Author: Zita Huang (m272898)
Lab09 Part 2
**********/
//Recieved help from MGSP Leader
#include <iostream>
#include <string>
using namespace std;

void map(int street, int avenue, int** P);

int main() {
    int streets, avenues;
    string junk, space;
    char coma;
    //get user input for the amount of streets and avenues desired
    cin >> streets >> junk >> avenues >> junk;
    
    //create a 2D array for the streets and avenues
    int** A = new int* [streets];
    for(int i  = 0; i < streets; i++){
        A[i] = new int[avenues];
    }
    for(int i = 0; i < streets; i++){
        for(int j  = 0; j < avenues; j++){
            cin >> A[i][j];
        }
    }
    
    cout << "> ";
    string cmd;
    cin >> cmd; //take in the command
    while(cmd != "quit"){
        //If statement for the crash command
        if(cmd == "crash"){
            int street, avenue;
            char stuff;
            cin >> street >> stuff >> stuff >> junk 
                >> avenue >> junk;

            //add 1 to the number of the street and avenue 
            if(street > 0 && street <= streets && avenue > 0 && avenue <= avenues){
                A[street][avenue]+= 1;
                map(streets, avenues, A);
            }
        }

        cout << "> ";
        cin >> cmd;
    }

    // Free allocated memory
    for (int i = 0; i < streets; i++) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}

void map(int street, int avenue, int** map){
    for(int i  = 0; i < street; i++){
        for(int j = 0; j < avenue; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

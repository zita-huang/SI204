/*************
Filename: p1.cpp
Author: Zita Huang(m272898)
Lab 07 Part 1
*************/
#include <iostream>
using namespace std;
    int* read(int N);
    int print(int* A, int N);
    bool isInOrder(int* A, int N);

    int main(){
        char c;
        int N;
        cin >> c >> c >> N >> c;

        int* A = read(N);
        print(A,N);
        if(isInOrder(A,N))
            cout << "Is in order!" << endl;
        else
            cout << "Is not in order!" << endl;

        delete[] A;
        return 0;
    }

    int* read(int N){
        int* array = new int [N];
        for(int i = 0; i < N; i++){
            cin >> array[i];
        }
        return array;
    }

    int print(int* A, int N){
        int dash = 0;
        for( int i = 0; i < N; i++){
            cout << A[i] << " ";
            dash = N * 2 + 1;
        }
        cout << endl;
        for(int i = 0; i < dash; i++){
            cout << "-";
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            cout << char('A' + i) << " ";
        }
        cout << endl;

        return N;
    }

    bool isInOrder(int* A, int N){
        for(int i = 1; i < N ; i++){
            if(A[i] < A[i-1]){
                return false;
            }
        } 
        return true;
    }
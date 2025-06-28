/*********
Filename: fractals.cpp
Author: Zita Huang (m272898)
Fractals Library
*********/
#include <iostream>
#include <string>
using namespace std;
#include "fractals.h"

//part1.cpp function
void repeat(string s, int count){
    if(count <= 0)
        return;
    cout << s;//print out the string
    repeat(s, count - 1);//subtract the count number for the string
}

//part2.cpp
void cantor_row(int length){
    if(length == 1){
        cout << "X"; //base case
        return;
    }
    int third = length / 3; //math for the cantor row
    cantor_row(third); //output the first set(s) of X
    repeat("_", third); //output the first set(s) of _
    cantor_row(third); //output the last set(s) of X
}

//part3.cpp
void cantor_row(int width, int row_index){
    if(row_index == 1){
        repeat("X", width); //base case
        return;
    }

    int third = width / 3; //math for the cantor row
    int next_row = row_index / 3; //math for the next row in the cantor set

    cantor_row(third, next_row); //output the first set(s) of X
    repeat("_", third); //output the first set(s) of _
    cantor_row(third, next_row); // output the last set(s) of X
}

//part4.cpp
void repeat_cantor_row(int width, int row_index_count){
    //base case to return X
    if(row_index_count > width){
        return;
    }

    //pull the part3.cpp functionality 
    cantor_row(width, row_index_count);
    cout << endl;
    repeat_cantor_row(width, row_index_count * 3); //make sure to work for powers of 3
}
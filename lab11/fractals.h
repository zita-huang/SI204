/*********
Filename: fractals.h
Author: Zita Huang (m272898)
Fractals Library
*********/
#include <iostream>
#include <string>
using namespace std;

void repeat(string s, int count);
void cantor_row(int length);
void cantor_row(int width, int row_index);
void repeat_cantor_row(int width, int row_index_count);
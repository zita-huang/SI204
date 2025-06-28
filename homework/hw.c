/******
Filename: hw.c
Author: MIDN Zita Huang (m272898)
Homework 34
******/
#include <stdio.h>

    int main(){
        //identify the input types
        double x1, x2, y1, y2;
        //get user input for each value
        scanf("(%lf,%lf)\n", &x1, &y1);
        scanf("(%lf,%lf)", &x2, &y2);
        //calculate midpoiint
        double mx, my;
        mx = (x1 + x2) / 2.0;
        my = (y1 + y2) / 2.0;
        //print out the midpoint 
        printf("(%lf,%lf)\n", mx, my);

        return 0;
    }
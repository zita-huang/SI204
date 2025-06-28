/*********
Filename: p1.cpp
Author: Zita Huang (m272898)
Lab09 Part 1
*********/
//Recieved help from MGSP Leader
#include <iostream>
#include <fstream>
using namespace std;

int users = 610;
int movies = 9724;

    int main(){
        //create 2D array to store the user and rating

        double** ratings;
        ratings = new double* [users];
        for(int i  = 0; i < users; i++){
            ratings[i] = new double[movies];
            for (int j = 0; j < movies; j++) {
                ratings[i][j] = 0;
            }
        }
        //read in the file 
        ifstream fin("ratings.tsv");
        if(!fin){
            cout << "file does not exist!";
            return 1;
        }

        //Store the data into the array
        int userID, movieID;
        double ratingValue;
        string junk;
        fin >> junk >> junk >> junk;
        while(fin >> userID >> movieID >> ratingValue){
            if(userID >= 0 && userID < users && movieID >= 0 && movieID < movies){
                ratings[userID][movieID] = ratingValue; 
            }
        }

        //input command
        string cmd;
        int ID;
        while(cin >> cmd){
            //if statement for the quit command
            if(cmd == "quit"){
                break;
            }
            //if statement for the movie command
            else if(cmd == "movie"){
                int movieID, count = 0;
                double sum = 0;
                cin >> movieID;
                //count the ratings and the movie watched by how many users
                for(int i = 0; i < users; i++){
                    if(ratings[i][movieID] > 0){
                        sum += ratings[i][movieID];
                        count++;
                    }
                }
                //do average computation
                if(count > 0){
                    double avg;
                    avg = sum / count;
                    cout << avg << endl;
                }
            }
            //if statement for the user command
            else if(cmd == "user"){
                int userID, count = 0;
                double sum = 0;
                cin >> userID;

                //count up the movies and ratings that user has watched/rated
                for(int j = 0; j < movies; j++){
                    if(ratings[userID][j] > 0){
                        sum += ratings[userID][j];
                        count++;
                    }
                }
                //compute average for the user
                if(count > 0){
                    double avg;
                    avg = sum / count;
                    cout << avg << endl;
                }
            }
        }
        // Free memory
        for (int i = 0; i < users; i++) {
            delete[] ratings[i];
        }
        delete[] ratings;

        return 0;
}



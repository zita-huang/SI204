/***********
Filename: rowshift.cpp
Author: MIDN Zita Huang (m272898)
Project 1 Part 4
***********/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

    int main()
    {
        string file1, file2, outfile;
        int rowshift;
        cout << "Foreground file: ";
        cin >> file1;
        cout << "Background file: ";
        cin >> file2;
        cout << "Row shift: ";
        cin >> rowshift;
        cout << "Output file: ";
        cin >> outfile;

        ifstream fin_fg(file1), fin_bg(file2);
        ofstream fout(outfile);

        if(!fin_fg || ! fin_bg || !fout)
        {
            cout << "Error: Input file not found" << endl;
            return 1;
        }

        string numfg, numbg;
        int wfg, hfg, mvfg, wbg, hbg, mvbg;
        fin_fg >> numfg >> wfg >> hfg >> mvfg;
        fin_bg >> numbg >> wbg >> hbg >> mvbg;

        if(numfg != "P3" || numbg != "P3")
            {
                cout << "Error: Images have different sizes" << endl;
                return 1;
            }
        
        fout << numbg << endl;
        fout << wbg << " " << hbg << endl;
        fout << mvbg << endl;


        if(rowshift > hbg-hfg)
        {
            cout << "Error: The foreground goes past the background" << endl;
            return 1;
        }

        int fg, fr, fb, br, bg, bb;
        
        // I. i < rs -> ONLY print the BACKGROUND
        // II. rs < i < rs + hfg
        //     a) j < wfg -> do all the greenscreen stuff, cin fg and bg
        //     b ) wfg < j < wbg -> do just the background, don't cin fg
        // III. rs + hfg < i < hbg

        // Case I.
        for (int i = 0; i < rowshift; i++) {
            for(int j = 0; j < wbg; j++) {
                fin_bg >> br >> bg >> bb;
                fout << br << " " << bg << " " << bb << " ";
            }
        }
        // Case II.
        for(int i = rowshift; i < rowshift + hfg; i++) {
            for(int j = 0; j < wfg; j++) {
                fin_fg >> fr >> fg >> fb;
                fin_bg >> br >> bg >> bb;
                if(fg == 255 && fr == 0 && fb == 0)
                {
                    fout << br << " " << bg << " " << bb << " ";
                }
                else 
                {
                    fout << fr << " " << fg << " " << fb << " ";
                }
            }
            for(int j = wfg; j < wbg; j++) {
                fin_bg >> br >> bg >> bb;
                fout << br << " " << bg << " " << bb << " ";
            }
        }
        // Case III.
        for (int i = rowshift + hfg; i < hbg; i++) {
            for(int j = 0; j < wbg; j++) {
                fin_bg >> br >> bg >> bb;
                fout << br << " " << bg << " " << bb << " ";
            }
        }
        // //create the top of bill without green screen
        // for(int i = 0; i < hbg ; i++)
        // {
        //     fin_fg >> fr >> fg >> fb;
        //     fin_bg >> br >> bg >> bb;
        //     fout << br << " " << bg << " " << bb << " ";
        //     // iterate through height of foreground with green screen       
        //     for(int j = 0; j <= hfg; j++)
        //     {
        //         fin_fg >> fr >> fg >> fb;
        //         fin_bg >> br >> bg >> bb;
        //         if(fg == 255 && fr == 0 && fb == 0)
        //             {
        //                 fout << br << " " << bg << " " << bb << " ";
        //             }
        //             else 
        //             {
        //                 fout << fr << " " << fg << " " << fb << " ";
        //             }
                
        //     }
        //     //the bottom of bill without green screen
        //     for(int k = 0; k < hbg; k++)
        //     {
        //         fin_fg >> fr >> fg >> fb;
        //         fin_bg >> br >> bg >> bb;
        //         fout << br << " " << bg << " " << bb << " ";
        //     }
        // }
        cout << "Image saved to " << outfile << endl;
        fout << endl;

        return 0;
    }
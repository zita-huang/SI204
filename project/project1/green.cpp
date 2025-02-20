/**********
Filename: green.cpp
Name: MIDN Zita Huang(m272898)
Project 1 Part 3
**********/
//Used class notes as reference
//Referenced parts 1 and 2 for help
#include <iostream>
#include <fstream>
using namespace std;

    int main() 
    {
        //get user input
        string file1, file2, outfile;
        cout << "Foreground file: "; 
        cin >> file1;
        cout << "Background file: "; 
        cin >> file2;
        cout << "Output file: "; 
        cin >> outfile;
    
        ifstream fin_fg(file1), fin_bg(file2);
        ofstream fout(outfile);
    
        //If file is not found, output error
        if (!fin_fg || !fin_bg || !fout) 
        {
            cout << "Error: Input file not found" << endl;
            return 1;
        }

        string numfg, numbg;
        int wfg, hfg, mvfg, wbg, hbg, mvbg;
        fin_fg >> numfg >> wfg >> hfg >> mvfg;
        fin_bg >> numbg >> wbg >> hbg >> mvbg;

        if(numfg != "P3" || numbg != "P3" ||
            mvfg != 255 || mvbg != 255 ||
            wfg != wbg || hfg != hbg)
            {
                cout << "Error: Images have different sizes" << endl;
                return 1;
            }

        fout << numfg << endl;
        fout << wfg << " " << hfg << endl;
        fout << mvfg << endl;

        int fr, fg, fb, br, bg, bb;
        for(int i = 0; i < hbg; i++)
        {
            for(int j = 0; j < wfg; j++)
            {
                if(!(fin_fg ) || !(fin_bg))
                {
                    cout << "Error reading pixel" << endl;
                    return 1;
                }

                fin_fg >> fr >> fg >> fb;
                fin_bg >> br >> bg >> bb;

                //If statement to replace the green pixels with the background
                //If the pixel is not green then it will stay the same
                //and move on
                if(fg == 255 && fr == 0 && fb == 0)
                {
                    fout << br << " " << bg << " " << bb << " ";
                }
                else 
                {
                    fout << fr << " " << fg << " " << fb << " ";
                }
                
            }
            fout << endl;
        }

        

        cout << "Image saved to " << outfile << endl;
        return 0;
    }
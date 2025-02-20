#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
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

    if (!fin_fg || !fin_bg || !fout) {
        cerr << "Error: Input file not found" << endl;
        return 1;
    }

    string numfg, numbg;
    int wfg, hfg, mvfg, wbg, hbg, mvbg;

    fin_fg >> numfg >> wfg >> hfg >> mvfg;
    fin_bg >> numbg >> wbg >> hbg >> mvbg;

    if (numfg != "P3" || numbg != "P3") {
        cerr << "Error: Images are not P3" << endl;
        return 1;
    }



    fout << numbg << endl;
    fout << wbg << " " << hbg << endl;
    fout << mvbg << endl;

    if (rowshift > hbg - hfg) {
        cerr << "Error: The foreground goes past the background" << endl;
        return 1;
    }

    int fr, fg, fb, br, bg, bb;

    // Skip the initial rows in the foreground file if rowshift is positive
    for (int i = 0; i < rowshift && i < hfg; ++i) {
        for (int j = 0; j < wfg; ++j) {
            fin_fg >> fr >> fg >> fb; // Discard these pixels
        }
    }


    for (int i = 0; i < hbg; i++) {
        for (int j = 0; j < wbg; j++) {
            fin_bg >> br >> bg >> bb;

            if (i >= rowshift && i < rowshift + hfg) {
                fin_fg >> fr >> fg >> fb; // Read foreground pixel

                if (fg == 255 && fr == 0 && fb == 0) {
                    fout << br << " " << bg << " " << bb << " ";
                } else {
                    fout << fr << " " << fg << " " << fb << " ";
                }
            } else {
                fout << br << " " << bg << " " << bb << " ";
            }
        }
        fout << endl;
    }

    cout << "Image saved to " << outfile << endl;

    return 0;
}
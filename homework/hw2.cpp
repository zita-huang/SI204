#include <iostream>
using namespace std;

int main() {
    int height, width, offset;

    cout << "Enter height (greater than 2): ";
    cin >> height;
    cout << "Enter width  (greater than 2): ";
    cin >> width;
    cout << "Enter offset: ";
    cin >> offset;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < offset; j++) cout << ' ';
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
    
    return 0;
}



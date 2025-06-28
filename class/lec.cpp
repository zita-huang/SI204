#include <iostream>
#include <fstream>
using namespace std;

int a, b;
cin >> a >> b;
for(int i=1; i < a; i++)
{
  for(int j=b; j >= 0; j -= 2)
    cout << i*j << " ";

  cout << endl;
}
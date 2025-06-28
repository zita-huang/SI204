// letter.h (given)
#pragma once
struct Letter
{
  char A[4][7];
};

Letter loadLetter(ifstream& fin);
void drawLetter(Letter* letters, char c);
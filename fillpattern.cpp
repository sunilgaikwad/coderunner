#include <iostream>
using namespace std;
int M = 5;
int N = 6;
int fillpattern(int x, int y, bool *color)
{
  //check for bounds of x
  if(x >= M || x < 0)
    return 0;

  //check for bounds of y
  if(y >= N || y < 0)
    return 0;

  //Check if already vivited
  if(*(color + (x * (M + 1)) + y) == false)
  {

    *(color + (x * (M + 1)) + y) = true;
    return 1 + fillpattern(x + 1, y, color)
             + fillpattern(x - 1, y, color)
             + fillpattern(x, y + 1, color)
             + fillpattern(x, y - 1, color);
  }

  return 0;
}

int main(int args, const char *argv[])
{
   //Create the fill

   bool color[5][6] = {{true,  true,  true,  true,  false, false},
                      { true,  true,  false, true,  false, false},
                      { true,  false, false, false,  true,  false},
                      { true,  true,  true,  false, true,  false},
                      { false, false, true,  true,  true,  false}};

    int noofblocks = fillpattern(1, 2, &color[0][0]);
    cout<<"No of blocks filled "<<noofblocks<<endl;
    return 0;
}

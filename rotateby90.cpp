#include<iostream>
using namespace std;

void printmatrix(int *image)
{
  for(int i = 0; i < 6; i++)
  {
   for(int j = 0; j < 6; j++)
   {
     cout<<*(image + i * 6 + j)<<" ";
     if(j == 5)
      cout<<endl;
   }
  }
  cout<<endl;
}

int main(int args, const char *argv[])
{
   //Create the fill
   int image[6][6] = {{  1,   2,    3,    4,   5,  6},
                      { 20,  21,   22,   23,  24,  7},
                      { 19,  32,   33,   34,  25,  8},
                      { 18,  31,   36,   35,  26,  9},
                      { 17,  30,   29,   28,  27,  10},
                      { 16,  15,   14,   13,  12,  11}};

   printmatrix(&image[0][0]);
   int size = 6;
   int start = 0;
   int end = 5;
   int temp = 0;
   //this is the number of times the loop will go to the last depth
   while(size > 0)
   {
     for(int i = start; i < end; i++)
     {
       temp = image[start][i];
       image[start][i] = image[end + start - i][start];
       image[end + start - i][start] = image[end][end + start - i];
       image[end][end + start - i] = image[i][end];
       image[i][end] = temp;
     }

     size = size - 2;
     start = start + 1;
     end = start + size - 1;

   }

  printmatrix(&image[0][0]);

}

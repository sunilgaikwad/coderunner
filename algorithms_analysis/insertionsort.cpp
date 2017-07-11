#include <iostream>
using namespace std;

int main()
{
  int arry[7] = {7, 6, 5, 4, 3, 2, 1};

  int i = 1;
  int j = i - 1;

  for(int start = i; start < 7; start++)
  {
    j = start - 1;
    if(arry[start] >= arry[j])
      continue;
    else
    {
      int k = start;
      j = k - 1;
      while(j >= 0 && arry[j] > arry[k])
      {
        int temp = arry[j];
        arry[j] = arry[k];
        arry[k] = temp;
        k = k - 1;
        j = k - 1;
      }
    }
  }

  for(int i = 0; i < 7; i++)
   cout<<arry[i]<<" ";
  cout<<endl;
  return 0;
}

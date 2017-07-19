//Big O of N square

#include <iostream>
using namespace std;

template <typename T>
void insertionsort(T *arry, int size)
{
  int noofelements = size/sizeof(T);
  int i = 1;
  int j = i - 1;

  for(int start = i; start < noofelements; start++)
  {
    j = start - 1;
    if(*(arry + start) >= *(arry + j))
      continue;
    else
    {
      int k = start;
      j = k - 1;
      while(j >= 0 && *(arry + j) > *(arry + k))
      {
        T temp = *(arry + j);
        *(arry + j) = *(arry + k);
        *(arry + k) = temp;
        k = k - 1;
        j = k - 1;
      }
    }
  }

  for(int i = 0; i < noofelements; i++)
   cout<<*(arry + i)<<" ";

}

int main()
{
  int arry[7] = {7, 6, 5, 4, 3, 2, 1};
  insertionsort<int>(&arry[0], sizeof(arry));
  return 0;
}

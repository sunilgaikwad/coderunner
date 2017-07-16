//Big O complexity for mergesort is nlogn.

#include <iostream>
using namespace std;

void merge(int *arry, int start, int end)
{
  if(start >= end)
    return;

  int size = end - start + 1;
  int temp[size];

  int mid = (end + start)/2;
  int start1 = start;
  int end1 = mid;
  int start2 = mid + 1;
  int end2 = end;

  int tempi = 0;
  while(start1 <= end1 && start2 <= end2)
  {
    if(*(arry + start1) <=  *(arry + start2))
    {
      temp[tempi] = *(arry + start1);
      start1++;
      tempi++;
    }
    else
    {
      temp[tempi] = *(arry + start2);
      start2++;
      tempi++;
    }
  }

  //Move remaining elements
  while(start1 <= end1)
  {
    temp[tempi] = *(arry + start1);
    start1++;
    tempi++;
  }
  while(start2 <= end2)
  {
    temp[tempi] = *(arry + start2);
    start2++;
    tempi++;
  }

  //MOVE FROM TEMP ARRAY TO original
  tempi = 0;
  for(int i = start; i <= end; i++)
  {
    *(arry + i) = temp[tempi];
    tempi++;
  }
}

void mergesort(int *arry, int start, int end)
{
  if(start < end)
  {
  cout<<"Start "<<start<<" End "<<end<<endl;
  int mid = (end + start)/2;

  mergesort(arry, start, mid);
  mergesort(arry, mid + 1, end);

  merge(arry, start, end);
  }
}

int main()
{
  int arry[] = {7, 3, 2, 9, 5, 1, 4, 0, 77, 43, 97, 234, 12, 80, 47, 25, 997, 2416, 21, 73};
  int size = sizeof(arry)/sizeof(int);

  //Mergesort
  mergesort(&arry[0], 0, size - 1);

  for(int i = 0; i < size; i++)
  {
     cout<<arry[i]<<" ";
  }
}

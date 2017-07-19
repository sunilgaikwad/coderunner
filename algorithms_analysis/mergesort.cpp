//Big O complexity for mergesort is nlogn.

#include <iostream>
using namespace std;

template <typename T>
void merge(T *arry, int start, int end)
{
  if(start >= end)
    return;

  int size = end - start + 1;
  T temp[size];

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

template <typename T>
void mergesort(T *arry, int start, int end)
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
  char arry[] = {'b', 'c', 'a', 'd'};
  int size = sizeof(arry)/sizeof(char);

  //Mergesort
  mergesort<char>(&arry[0], 0, size - 1);

  for(int i = 0; i < size; i++)
  {
     cout<<arry[i]<<" ";
  }
}

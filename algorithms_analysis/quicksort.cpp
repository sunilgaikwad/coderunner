#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

template <typename T>
int randomized_partition(vector<T> &vec, int start, int end)
{
  int rindex = rand() % (end - start) + start;
  T rtemp = vec[rindex];
  vec[rindex] = vec[start];
  vec[start] = rtemp;

  T pivotval = vec[start];
  int i = start;
  int j = start + 1;
  while(j <= end)
  {
    if(vec[j] < pivotval)
    {
      i++;
      T temp = vec[i];
      vec[i] = vec[j];
      vec[j] = temp;
    }
    j++;
  }
  //swap pivot with new pivot
  T temp = vec[start];
  vec[start] = vec[i];
  vec[i] = temp;

  return i;
}


template <typename T>
int partition(vector<T> &vec, int start, int end)
{
  T pivotval = vec[start];
  int i = start;
  int j = start + 1;
  while(j <= end)
  {
    if(vec[j] < pivotval)
    {
      i++;
      T temp = vec[i];
      vec[i] = vec[j];
      vec[j] = temp;
    }
    j++;
  }
  //swap pivot with new pivot
  T temp = vec[start];
  vec[start] = vec[i];
  vec[i] = temp;

  return i;
}

template <typename T>
void quicksort(vector<T> &vec, int start, int end)
{
  int pivotindex = partition(vec, start, end);
  if(start < pivotindex - 1)
   quicksort(vec, start, pivotindex - 1);
  if(pivotindex + 1 < end)
    quicksort(vec, pivotindex + 1, end);
}

template <typename T>
void randomized_quicksort(vector<T> &vec, int start, int end)
{
  int pivotindex = randomized_partition(vec, start, end);
  if(start < pivotindex - 1)
   randomized_quicksort(vec, start, pivotindex - 1);
  if(pivotindex + 1 < end)
    randomized_quicksort(vec, pivotindex + 1, end);
}

int main()
{
  vector<int> vec = {7, 2, 3, 8, 3, 0, 1, 2};
  randomized_quicksort(vec, 0, vec.size() - 1);
  for(int i = 0; i < vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
}

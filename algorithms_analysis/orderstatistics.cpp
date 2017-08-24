#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int partition(vector<T> &vec, int start, int end)
{
  int pval = vec[start];
  int i = start;
  int j = start + 1;
  while(j <= end)
  {
    if(vec[j] < pval)
    {
      i++;
      T temp = vec[j];
      vec[j] = vec[i];
      vec[i] = temp;
    }
    j++;
  }

  T ptemp = vec[start];
  vec[start] = vec[i];
  vec[i] = ptemp;

  return i;
}

template <typename T>
T nthsmallest(vector<T> &vec, int start, int end, int nth)
{
  if(start < end)
  {
    int pivot = partition(vec, start, end);
    if(pivot - start + 1 == nth)
    {
      return vec[pivot];
    }
    else
    {
      if(pivot - start + 1 > nth)
      {
        //search left
        return nthsmallest(vec, start, pivot - 1, nth);
      }
      else
      {
        return nthsmallest(vec, pivot + 1, end, nth - (pivot - start + 1));
      }
    }
  }
  else
  {
    throw std::exception();
  }
}

int main()
{
  vector<int> vec = {7, 12, 13, 8, 9, 0, 1, 2};
  int val = nthsmallest(vec, 1, vec.size() - 1, 4);
  cout<<"Nth smallest is : "<<val;
}

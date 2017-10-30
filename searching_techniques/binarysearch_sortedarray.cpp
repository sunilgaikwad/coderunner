//binary search on a sorted array

#include "binarysearch_sortedarray.h"

template<typename T>
int binarysearch_recursive(vector<T> &v, int start, int end, T tosearch) {
  if(start <= end) {
    int mid = (start + end)/2;
    if(v[mid] == tosearch)
     return mid;
    else if(v[mid] > tosearch)
      return binarysearch_recursive(v, start, mid - 1, tosearch);
    else
      return binarysearch_recursive(v, mid + 1, end, tosearch);
    }
  else {
    return -1;
  }
}

template<typename T>
int binarysearch_iterative(vector<T> &v, int start, int end, T tosearch) {
  while(start <= end) {
    int mid = (start + end)/2;
    if(v[mid] == tosearch)
     return mid;
    else if(v[mid] > tosearch)
      end = mid - 1;
    else
      start = mid + 1;
    }
    return -1;
}

template<typename T>
int binarysearch(T tosearch)
{
  std::vector<double> v;
  v.push_back(2.1);
  v.push_back(4.2);
  v.push_back(6.3);
  v.push_back(7.4);
  v.push_back(9.5);
  v.push_back(10.6);
  v.push_back(12.7);
  v.push_back(21.8);

  int end = v.size() - 1;
  int result1 = binarysearch_recursive(v, 0, end, tosearch);
  int result2 = binarysearch_iterative(v, 0, end, tosearch);

  if(result1 != result2)
  {
    return -2;
  }
  else
  {
    return result1;
  }
}

template int binarysearch<double>(double tosearch);
template int binarysearch_recursive<double>(vector<double> &v, int start, int end, double tosearch);
template int binarysearch_iterative<double>(vector<double> &v, int start, int end, double tosearch);

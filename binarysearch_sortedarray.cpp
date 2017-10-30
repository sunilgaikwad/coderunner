//binary search on a sorted array

#include "binarysearch_sortedarray.h"


int binarysearch_recursive(vector<double> &v, int start, int end, double tosearch) {
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

//template<typename T>
int binarysearch_iterative(vector<double> &v, int start, int end, double tosearch) {
  while(start <= end) {
    int mid = (start + end)/2;
    if(v[mid] == tosearch)
     return mid;
    else if(v[mid] > tosearch)
      end = mid - 1;
    else
      start = mid + 1;
    }
    return 1;
}

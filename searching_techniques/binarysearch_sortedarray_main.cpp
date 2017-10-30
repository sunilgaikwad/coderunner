#include "binarysearch_sortedarray.h"

int main() {
  std::vector<double> v;
  v.push_back(2.1);
  v.push_back(4.2);
  v.push_back(6.3);
  v.push_back(7.4);
  v.push_back(9.5);
  v.push_back(10.6);
  v.push_back(12.7);
  v.push_back(21.8);

  double tosearch = 9.5;
  int end = v.size() - 1;
  int result1 = binarysearch_recursive(v, 0, end, tosearch);
  int result2 = binarysearch_iterative(v, 0, end, tosearch);
  if(result1 != result2)
    cout<<"Bug in the recursive vs iterative algorithm"<<endl;
  else
  cout<<"result "<<result1<<endl;
}

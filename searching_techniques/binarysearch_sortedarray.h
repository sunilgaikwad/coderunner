#ifndef BINARYSEARCH_SORTEDARRAY_H_
#define BINARYSEARCH_SORTEDARRAY_H_
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int binarysearch(T tosearch);

template<typename T>
int binarysearch_recursive(vector<T> &v, int start, int end, T tosearch);

template<typename T>
int binarysearch_iterative(vector<T> &v, int start, int end, T tosearch);

#endif  // BINARYSEARCH_SORTEDARRAY_H_

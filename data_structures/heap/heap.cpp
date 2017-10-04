#include "heap.h"
using namespace std;
namespace notastd
{
template <typename T>
void Heap<T>::DownHeapify(int index)
{
  int lindex = (2 * index) + 1;
  int rindex = (2 * index) + 2;
  int size = vec.size();
  bool lvalid = false;
  bool rvalid = false;
  if(lindex < size)
    lvalid = true;
  if(rindex < size)
    rvalid = true;
  if(rvalid && lvalid)
  {
    if(vec[lindex] < vec[rindex])
    {
      if(vec[lindex] < vec[index])
      {
        T temp = vec[index];
        vec[index] = vec[lindex];
        vec[lindex] = temp;
        DownHeapify(lindex);
      }
    }
    else
    {
      if(vec[rindex] < vec[index])
      {
        T temp = vec[index];
        vec[index] = vec[rindex];
        vec[rindex] = temp;
        DownHeapify(rindex);
      }
    }
  }
  else if(lvalid)
  {
      if(vec[lindex] < vec[index])
      {
        T temp = vec[index];
        vec[index] = vec[lindex];
        vec[lindex] = temp;
      }
  }
}

template <typename T>
void Heap<T>::UpHeapify(int index)
{
  if(index < 0)
   return;

  int parent = (index - 1)/2;
  if(vec[parent] > vec[index])
  {
    T temp = vec[parent];
    vec[parent] = vec[index];
    vec[index] = temp;
    UpHeapify(parent);
  }
}

template <typename T>
void Heap<T>::Enqueue(T value)
{
  vec.push_back(value);
  int size = vec.size();
  if( size > 1)
  {
    UpHeapify(size - 1);
  }
}

template <typename T>
T Heap<T>::Dequeue()
{
  if(vec.size() == 0)
  {
    cout<<"Heap empty"<<endl;
    return - 1;
  }
  else if(vec.size() == 1)
  {
    T toreturn =  vec[0];
    vec.pop_back();
    return toreturn;
  }
  T toreturn =  vec[0];
  vec[0] = vec[vec.size() - 1];
  vec.pop_back();
  DownHeapify(0);
  return toreturn;
}

template class Heap<int>;
template class Heap<double>;

}

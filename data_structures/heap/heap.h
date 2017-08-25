#include <iostream>
#include <vector>
using namespace std;

namespace notastd
{
  template <class T>
  class Heap
  {
  private:
    vector<T> vec;
    void DownHeapify(int index);
    void UpHeapify(int index);
  public:
    void Enqueue(T value);
    T Dequeue();
  };
}

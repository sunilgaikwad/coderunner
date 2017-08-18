#include <iostream>
using namespace std;

namespace notastd
{
  template <class T>
  class queue
  {
  private:
    static int size;
    int front; //pop from front
    int back; //add to the back
    T arry[6];

  public:
    queue():front(-1), back(-1)
    {}
    void enqueue(T value);
    void dequeue();
    void print();
  };
}

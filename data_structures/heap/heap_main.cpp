#include <iostream>
#include "heap.h"

using namespace notastd;

int main()
{
  Heap<int> h;
  h.Enqueue(3);
  h.Enqueue(7);
  h.Enqueue(1);
  h.Enqueue(2);
  h.Enqueue(4);
  h.Enqueue(9);

  cout<<h.Dequeue()<<endl;
  cout<<h.Dequeue()<<endl;
  cout<<h.Dequeue()<<endl;
  cout<<h.Dequeue()<<endl;
  cout<<h.Dequeue()<<endl;
  cout<<h.Dequeue()<<endl;
  cout<<h.Dequeue()<<endl;
}

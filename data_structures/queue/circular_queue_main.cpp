#include "circular_queue.h"
using namespace notastd;

int main()
{
  queue<int> cq;
  cq.enqueue(1);
  cq.enqueue(2);
  cq.enqueue(9);
  cq.enqueue(7);
  cq.enqueue(4);
  cq.enqueue(8);

  cq.dequeue();
  cq.dequeue();

  cq.enqueue(1);
  cq.enqueue(6);

  cq.dequeue();

  cq.enqueue(9);
  cq.enqueue(3);
  cq.enqueue(2);

  cq.dequeue();
  cq.dequeue();

  cq.print();
}

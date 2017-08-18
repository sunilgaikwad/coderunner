#include "circular_queue.h"

namespace notastd
{
    template <class T>
    void queue<T>::enqueue(T value)
    {
      if(front == -1 && back == -1)
      {
        front = back = 0;
        arry[front] = value;
      }
      else if((front == 0 && back == 5 ) || ((front - back) == 1))
      {
        std::cout << "stack full" << '\n';
      }
      else
      {
        if(back == 5)
         back = 0;
        else
         back++;
        arry[back] = value;
      }
    }

    template <class T>
    void queue<T>::dequeue()
    {
      if(front == -1)
      {
        std::cout << "Stack empty" << '\n';
      }
      else if(front == back)
      {
        front = -1;
        back = -1;
      }
      else if(front == 5)
      {
        front = 0;
      }
      else
      {
        front++;
      }
    }
    
    template <class T>
    void queue<T>::print()
    {
      cout<<front<<" "<<back<<endl;
    }

    template class queue<int>;
    template class queue<double>;
    template class queue<char>;
  }

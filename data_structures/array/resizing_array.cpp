#include <iostream>
#include <string>
#include <exception>
using namespace std;

template <typename T>
class rArray
{
private:
  int a_size;
  int a_capacity;
  T *arry;

public:
  void construct(int size)
  {
    a_size = size;
    a_capacity = 40;
    if(size > a_capacity)
    {
      a_capacity = 2 * size;
      a_size = size;
    }
    else
    {
      int capratio = (size * 100)/a_capacity;
      if(capratio > 75)
      {
        a_capacity = a_capacity * 2;
      }
    }
    arry = new T[a_capacity];
  }

  rArray()
  {
    //set defaults
    a_size = 20;
    a_capacity = 40;
    arry = new T[a_capacity];
  }

  rArray(int size)
  {
    construct(size);
  }

  rArray(int size, T value)
  {
    construct(size);
    for(int i = 0; i < size; i++)
    {
      *(arry + i) = value;
    }
  }

  void resize()
  {
    int newsize = a_size + 1;
    int capratio = (newsize * 100)/a_capacity;
    if(capratio > 75)
    {
      a_capacity = a_capacity * 2;
      //Create a new array
      T *newarry = new T[a_capacity];
      for(int i = 0; i < a_size; i++)
      {
        *(newarry + i) = *(arry + i);
      }
      delete[] arry;
      arry = newarry;
    }
  }

  void push_back(T value)
  {
    resize();
    *(arry + a_size) = value;
    a_size = a_size + 1;
  }

  void pop_back()
  {
    if(a_size > 0)
    {
      T retval = *(arry + a_size - 1);
      a_size--;
    }
    else
    {
      std::cerr << "Array empty" << '\n';
    }
  }

  T back()
  {
    if(a_size > 0)
    {
      T retval = *(arry + a_size - 1);
      return retval;
    }
    else
    {
      std::cerr << "Array empty" << '\n';
      return 0;
    }
  }

  T const *begin()
  {
    return arry;
  }

  void insert(T const *it, T value)
  {
    resize();
    for(int i = a_size - 1; i >= 0; i--)
    {
        *(arry + i + 1) = *(arry + i);
    }
    *arry = value;
    a_size = a_size + 1;
  }

  int size()
  {
    return a_size;
  }

  int capacity()
  {
    return a_capacity;
  }

  bool isEmpty()
  {
    if(a_size == 0)
     return true;
    else
     return false;
  }

  void print()
  {
    cout<<"Arry size is " <<a_size<<endl;
    cout<<"Arry capacity is " <<a_capacity<<endl;
    cout<<"Array values are"<<endl;
    for(int i = 0; i < a_size;i++)
      cout<<*(arry + i)<<endl;
  }
};

int main()
{
  rArray<string> x(29, "abc");
  x.push_back("bca");
  x.insert(x.begin(), "xyz");
  cout<<"Begin is at "<<*(x.begin())<<endl;
  if(!x.isEmpty())
  {
    cout<<"Popped "<< x.back()<<endl;
    x.pop_back();
  }
  x.print();
  return 0;
}

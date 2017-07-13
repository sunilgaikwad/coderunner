#include <iostream>
using namespace std;

class rArray
{
private:
  int a_size;
  int a_capacity;
  int *arry;

public:
  rArray()
  {
    //set defaults
    a_size = 20;
    a_capacity = 40;
    arry = new int[a_capacity];
  }
  rArray(int size)
  {
    construct(size);
  }

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
    arry = new int[a_capacity];
  }

  rArray(int size, int value)
  {
    construct(size);
    for(int i = 0; i < size; i++)
    {
      *(arry + i) = value;
    }
  }

  void print()
  {
    cout<<"Arry size is " <<a_size<<endl;
    cout<<"Arry capacity is " <<a_capacity<<endl;
    cout<<"Array values are"<<endl;
    for(int i = 0; i < a_size;i++)
      cout<<*(arry + i)<<endl;
  }

  void resize()
  {
    int newsize = a_size + 1;
    int capratio = (newsize * 100)/a_capacity;
    if(capratio > 75)
    {
      a_capacity = a_capacity * 2;
      //Create a new array
      int *newarry = new int[a_capacity];
      for(int i = 0; i < a_size; i++)
      {
        *(newarry + i) = *(arry + i);
      }
      delete[] arry;
      arry = newarry;
    }
  }

  void push_back(int value)
  {
    resize();
    *(arry + a_size) = value;
    a_size = a_size + 1;
  }

  int pop_back()
  {
    int retval = *(arry + a_size - 1);
    a_size--;
    return retval;
  }
};

int main()
{
  rArray x(30, 10);
  x.push_back(11);
  cout<<"popped "<< x.pop_back()<<endl;
  x.print();
  return 0;
}

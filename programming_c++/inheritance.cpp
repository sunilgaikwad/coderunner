#include <iostream>
#include <iostream>
using namespace std;

// Cirmference = 2*pi*r;

class A
{
public:
  void print(){cout<<"came in A";}
};

class N : public A
{
public:
  void print(){cout<<"came in N";}
  void printx(int i){cout<<"came in B";}
};


int main()
{
  N n;
  n.print();
}

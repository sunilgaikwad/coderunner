#include <iostream>
#include <string>
using namespace std;

class Test
{
public:
  int x;

  void operator+(Test &rhs)
  {
    this->x = this->x + rhs.x;
  }
};

void operator+(string s1, string s2)
{

}

int main()
{
  Test a;
  Test b;
  a.x = 10;
  b.x = 20;
  a + b;
  cout<<a.x;

  string s1 = "sunil";
  string s2 = "Mona";
  s1+s2;
}

#include <iostream>
#include <string>
#include <stack>
#include <exception>
using namespace std;

bool isoperator(string value)
{
  int len = value.length();
  if(len == 1)
  {
    if(value.compare("*") == 0 ||
       value.compare("-") == 0 ||
       value.compare("+") == 0)
       {
         return true;
       }
       else
       {
         return false;
       }
  }
  else
  {
    return false;
  }
}

int compute(string op, int v1, int v2)
{
  if(op.compare("*") == 0)
  {
    return v1*v2;
  }
  else if(op.compare("-") == 0)
  {
    return v1-v2;
  }
  else if(op.compare("+") == 0)
  {
    return v1+v2;
  }
  else
  {
    cout<<"operation not supported";
    throw exception();
  }
}

int main()
{
  string input[7] = {"12", "7", "31", "*", "+", "4", "-"};
  stack<int> stk;
  for(int i = 0; i < 7; i++)
  {
    if(isoperator(input[i]))
    {
      //pop top two values
      int v2 = stk.top(); stk.pop();
      int v1 = stk.top(); stk.pop();
      int res = compute(input[i], v1, v2);
      stk.push(res);
    }
    else
    {
      std::string::size_type sz;
      stk.push(stoi(input[i], &sz));
    }
  }
  cout<<stk.top()<<endl;
  return 0;
}

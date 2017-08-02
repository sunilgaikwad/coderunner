#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <queue>
using namespace std;

map<char, int> prioritymap;

bool isoperator(char op)
{
  if(op == '+' || op == '*' || op == '-')
   return true;
  else
   return false;
}

bool islowpriority(char op1, char op2)
{
    int p1 = prioritymap[op1];
    int p2 = prioritymap[op2];

    if(p1 > p2)
     return true;
    else
     return false;
}
void infixtopostfix(string equation)
{
  int strlen = equation.length();
  stack<char> oper;
  queue<char> all;

  for(int i = 0; i < strlen; i++)
  {
    if(isoperator(equation[i]))
    {
      if(oper.empty())
      {
        oper.push(equation[i]);
      }
      else
      {
        while ((oper.empty() == false) && (islowpriority(equation[i], oper.top())))
        {
          char top = oper.top(); oper.pop();
          all.push(top);
        }
        oper.push(equation[i]);
      }
    }
    else
    {
      all.push(equation[i]);
    }
  }

  while(oper.empty() == false)
  {
    all.push(oper.top());
    oper.pop();
  }

  //print the queue. Could use stack also. Used queue for simplicity in printing
  while(all.empty() == false)
  {
    cout<<all.front()<<" ";
    all.pop();
  }

}
int main()
{
  //Set priorities
  prioritymap.insert(pair<char, int>('*', 1));
  prioritymap.insert(pair<char, int>('+', 2));
  prioritymap.insert(pair<char, int>('-', 3));

  string equation = "A+B*C-D-E*F+K";
  infixtopostfix(equation);
  return 0;
}

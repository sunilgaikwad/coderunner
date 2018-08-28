#include <iostream>
#include <vector>

using namespace std;

template<class T>
T highestProductOf3(const vector<T> &input)
{
size_t size = input.size();
if(size < 3)
{
  throw std::invalid_argument("Need atleast three numbers");
}

T hp3 = input[0] * input[1] * input[2];
T hp2 = input[0] * input[1];
T lp2 = input[0] * input[1];
T h = max(input[0], input[1]);
T l = min(input[0], input[1]);

for(size_t i = 2; i < size; i++)
{
  hp3 = max(max(hp3, (input[i] * hp2)),(input[i] * lp2));
  hp2 = max(max(hp2, (input[i] * h)),(input[i] * l));
  lp2 = min(min(lp2, (input[i] * h)),(input[i] * l));
  h = max(h, input[i]);
  l = min(l, input[i]);
}

return hp3;
}

int main()
{
  vector<int> input{-10, 1, 3, 2, -10};
  int result = highestProductOf3(input);
  cout<<"Highest product of three is " <<result<<endl;
}

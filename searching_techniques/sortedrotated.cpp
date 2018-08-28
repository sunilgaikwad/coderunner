#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsSorted(const string &leftStr, const string &rightStr)
{
  cout<<"Processing "<<leftStr<<" "<<rightStr<<endl;
  size_t leftLen = leftStr.length();
  size_t rightLen = rightStr.length();

  int i = 0;
  int j = 0;

  while(i < leftLen && j < rightLen)
  {
    if(leftStr[i] == rightStr[j])
    {
      i++;
      j++;
    }
    else if(leftStr[i] < rightStr[j])
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  if(i == leftLen && j == rightLen)
    return true;
  else if(i == leftLen)
     return true;
  else
     return false;
}

size_t findRotationPoint(const vector<string>& words)
{
    size_t size = words.size();
    if(size == 0)
      throw std::invalid_argument("Need atleast one element");

    if(size == 1)
      return 0;

    int start = 0;
    int end = size - 1;

    while(start <= end)
    {
      cout<<"Processing "<<words[start]<<" "<<words[end]<<endl;
      //check if already sorted
      if(words[start] <= words[end])
      {
        return start;
      }
      size_t mid = ((end - start)/2) + start;
      //left sorted
      if(words[start] <= words[mid])
      {
        start = mid + 1;
      }
      else
      {
        end = mid;
      }
    }

    return 0;
}

int main()
{
  /*vector<string> input{
    "ptolemaic",
    "retrograde",
    "supplant",
    "undulate",
    "xenoepist",
    "asymptote",  // <-- rotates here!
    "babka",
    "banoffee",
    "engender",
    "karpatka",
    "othellolagkage",
    "othellos",
    "othelloss"};*/
    vector<string> input{
      "p",
      "q",
      "r",
      "s",
      "t",
      "u",
      "v",
      "w",
      "x",
      "a", // <-- rotates here!
      "b",
      "c",
      "d"};

  size_t index = findRotationPoint(input);
  cout<<index;
}

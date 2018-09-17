#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string smallestSubString(const string &pattern, const string &str)
{
  size_t psize = pattern.length();
  size_t ssize = str.length();

  if(psize == 0 || ssize == 0)
    return string("");

  //Put the pattern into a set
  unordered_set<char> hset;
  for(size_t i = 0; i < psize; i++)
  {
    hset.insert(pattern[i]);
  }

  size_t start1 = 0;
  size_t start2 = 0;
  size_t startindex = 0;
  size_t endindex = ssize - 1;
  unordered_map<char, int> hmap;
  bool found = false;
  while(start1 < ssize && start2 <= (ssize - psize))
  {
    //First move start1
    while(hmap.size() != hset.size())
    {
      if(hset.find(str[start1]) != hset.end())
      {
        if(hmap.find(str[start1]) == hmap.end())
        {
          hmap.insert(make_pair(str[start1], 1));
        }
        else
        {
          hmap[str[start1]] = hmap[str[start1]] + 1;
        }
      }
      start1++;
    }

    if(start1 >= ssize)
    {
      if(found)
        break;
      else
      {
        if(hmap.size() != hset.size())
        {
          return string("");
        }
      }
    }

    //Move start2
    while(hmap.size() == hset.size())
    {
      if((start1 - 1 - start2) < (endindex - startindex))
      {
        found = true;
        startindex = start2;
        endindex = start1 - 1;
        cout<<startindex<<" "<<endindex<<endl;
      }

      if(hmap.find(str[start2]) != hmap.end())
      {
        if(hmap[str[start2]] > 1)
         hmap[str[start2]] = hmap[str[start2]] - 1;
        else
         hmap.erase(str[start2]);
      }
      start2++;
    }
  }
  return str.substr(startindex, endindex - startindex + 1);
}

int main()
{
  string uniquestr = "xyzr";
  string str = "xyyzryzx";
  string result = smallestSubString(uniquestr, str);
  cout<<result<<endl;
}

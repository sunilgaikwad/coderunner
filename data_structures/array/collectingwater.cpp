#include<iostream>
#include<vector>
using namespace std;

int collectedwater(const vector<int> &heights)
{
  int size = heights.size();
  if(size <= 1)
    return 0;

  int maxl = heights[0];
  int maxr = heights[size-1];

  int i = 0;
  int j = size - 1;

  while(i < size)
  {
    if(maxl <= heights[i])
    {
      maxl = heights[i];
      ++i;
    }
    else
      break;
  }
  while(j >= 0)
  {
    if(maxr <= heights[j])
    {
      maxr = heights[j];
      --j;
    }
    else
      break;
  }

  int water = 0;
  cout<<"maxl / maxr"<<maxl<<" "<<maxr<<endl;
  while(i <= j)
  {
    if(maxl < maxr)
    {
      if(maxl < heights[i])
        maxl = heights[i];
      else
      {
        water = water + (maxl - heights[i]);
        cout<<"maxl "<<water<<endl;
      }
      ++i;
    }
    else
    {
      if(maxr < heights[j])
        maxr = heights[j];
      else
      {
        water = water + (maxr - heights[j]);
        cout<<"maxr "<<water<<endl;
      }
      --j;
    }
  }
  return water;
}

int main()
{
  vector<int> heights{5,2,4,2,1,4};
  int collwater = collectedwater(heights);
  cout<<collwater;
}

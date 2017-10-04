#include <iostream>
#include <vector>
using namespace std;

void findtwoindexes(vector<int> &arry)
{
  int len = arry.size();

  //find first sorted array
  int start1 = 0;
  int prev1 = arry[start1];
  int end1 = 0;
  while((end1 < len) && (prev1 <= arry[end1]))
  {
   prev1 = arry[end1];
   end1++;
  }
  end1 = end1 - 1;
  cout<<"Array one start "<<start1<<" Array one end "<<end1<<endl;;
  if(end1 == len - 1)
  {
   cout<<"Index one "<<end1<<" Index two "<<end1;
   return;
  }

  //Find third sorted array
  int start3 = end1 + 1;
  int prev3 = arry[start3];
  int end3 = end1 + 1;

  int max = arry[end1];
  int min = arry[end1 + 1];
  int tmax = arry[end1];
  int tmin = arry[end1 + 1];

  while((end3 < len))
  {
    while(prev3 <= arry[end3])
    {
      if(arry[end3] < tmin)
      {
        tmin = arry[end3];
      }
      if(arry[end3] > tmax)
      {
        tmax = arry[end3];
      }
      prev3 = arry[end3];
      end3++;
    }
    if(end3 < len)
    {
      start3 = end3;
      prev3 = arry[start3];
      if(tmin < min) min = tmin;
      if(tmax > max) max = tmax;
    }
  }
  end3--;
  cout<<"Array three start "<<start3<<" Array three end "<<end3<<endl;
  cout<<"Min "<<min<<" Max "<<max<<endl;

  int i = end1;
  while(i >= 0 && arry[i] >= min)
  {
    i--;
  }
  i++;
  int j = end3;
  while(j >= start3 && arry[j] > max)
  {
    j--;
  }
  cout<<"first index "<<i<<" second index "<<j<<endl;
}

int main()
{
  //vector<int> arry = { 1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
  vector<int> arry = { 1, 2, 3};
  //vector<int> arry = { 1, 2, 4, 7, 10, 11, 6, 7, 16, 18, 19};
  findtwoindexes(arry);
}

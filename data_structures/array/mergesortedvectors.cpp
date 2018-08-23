#include <iostream>
#include <vector>
using namespace std;

void mergetwovectors(vector<int> &result, const vector<int> &to_merge)
{
  int res_size = result.size();
  int tomer_size = to_merge.size();

  if(res_size == 0)
  {
    result = to_merge;
    return;
  }
  if(tomer_size == 0)
   return;

  int i = 0;
  int j = 0;
  vector<int> temp;
  while(i < res_size && j < tomer_size)
  {
    if(result[i] < to_merge[j])
    {
      temp.push_back(result[i]);
      ++i;
    }
    else
    {
      temp.push_back(to_merge[j]);
      ++j;
    }
  }
  while(i < res_size)
  {
    temp.push_back(result[i]);
    ++i;
  }
  while(j < tomer_size)
  {
    temp.push_back(to_merge[j]);
    ++j;
  }
  result = temp;
}

vector<int> mergevectors(const vector<vector<int>> &vecs)
{
  vector<int> result;
  int v_size = vecs.size();
  if(v_size == 0)
    return result;
  else if(v_size == 1)
  {
    result = vecs[0];
    return result;
  }

  for(int i = 0; i < v_size; i++)
  {
    mergetwovectors(result, vecs[i]);
  }

  return result;
}

int main()
{
  vector<int> first{1, 2, 3, 15};
  vector<int> second{4, 8};
  vector<int> third{7, 9, 11, 13};
  vector<int> fourth{2};
  vector<vector<int>> input;
  input.push_back(first);
  input.push_back(second);
  input.push_back(third);
  input.push_back(fourth);
  vector<int> result = mergevectors(input);
  for(int i = 0; i < result.size(); i++)
  cout<<result[i]<<" ";
}

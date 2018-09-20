#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int maxValueOfSack(const vector<int> &weights, const vector<int> &values, int capacity, int index)
{
  static unordered_map<int, int> hmap;
  if(capacity <= 0)
    return 0;
  if(index < 0)
     return 0;

  if(hmap.find(index) != hmap.end())
    return hmap[index];

  if(weights[index] > capacity)
    return maxValueOfSack(weights, values, capacity, index - 1);
  int value1 = values[index] + maxValueOfSack(weights, values, capacity - weights[index], index - 1);
  int value0 = maxValueOfSack(weights, values, capacity, index - 1);
  int maximum = max(value1, value0);
  hmap.insert(make_pair(index, maximum));
  return maximum;
}
int maximumValueOfSackRecursive(const vector<int> &weights, const vector<int> &values, const int &capacity)
{
  if(weights.size() == 0)
    return 0;
  if(values.size() == 0)
    return 0;

  return maxValueOfSack(weights, values, capacity, static_cast<int>(weights.size() - 1));
}

int main()
{
  vector<int> weights{10, 20, 30};
  vector<int> values{60, 100, 120};
  int capacity = 50;
  cout<<maximumValueOfSackRecursive(weights, values, capacity);
}

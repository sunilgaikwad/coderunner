#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> sortScores(const vector<int> &scores, const int &maxscore)
{
    int size = scores.size();
    if(size < 0)
     throw invalid_argument("Invalid input");

    unordered_map<int, int> hmap;
    unordered_map<int, int>::iterator it;

    for(int i = 0; i < size; i++)
    {
      it = hmap.find(scores[i]);
      if(it != hmap.end())
      {
        it->second = it->second + 1;
      }
      else
        hmap.insert(make_pair(scores[i], 1));
    }

    vector<int> sorted;
    for(int i = maxscore; i >= 0; i--)
    {
      it = hmap.find(i);
      if(it != hmap.end())
      {
        for(int j = 0; j < it->second; j++)
          sorted.push_back(i);
      }
    }

    return sorted;
}

int main()
{
  vector<int> scores {37};
  vector<int> sortedScores = sortScores(scores, 100);

  for(int i = 0; i < sortedScores.size(); i++)
   cout<<sortedScores[i]<<endl;
}

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool Canwatch(const vector<double> &movielen, double flighttime)
{
  int size = movielen.size();
  if(size < 2)
    throw invalid_argument("Need atleast two titles to watch");

  unordered_set<double> hset;
  unordered_set<double>::iterator it;
  for(int i = 0; i < size; i++)
  {
    if(movielen[i] >= flighttime)
      continue;
    double timeleft = flighttime - movielen[i];
    it = hset.find(timeleft);
    if(it != hset.end())
    {
      return true;
    }
    else
    {
      hset.insert(movielen[i]);
    }
  }
  return false;
}
int main()
{
  vector<double> movielen {3, 8};
  if(Canwatch(movielen, 3))
    cout<<"Can watch two movies";
  else
    cout<<"Cannot watch two movies";
}

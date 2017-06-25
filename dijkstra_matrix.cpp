//Implement dijkstra using two dimentional array

#include <iostream>
#include <climits>
using namespace std;

bool NotAllVisited(bool *svisited)
{
    for(int i = 0; i < 6; i++)
    {
      if(*(svisited + i) == false)
      {
        return true;
      }
    }
    return false;
}

int FindSmallest(int *spaths, bool *svisited)
{
  int smallestindex = 0;
  int smallestvalue = 0;
  bool onlyonce = true;
  for(int i = 0; i < 6; i++)
  {
    if(*(svisited + i) == false)
    {
      if(onlyonce)
      {
        smallestindex = i;
        smallestvalue = *(spaths + i);
        onlyonce = false;
      }
      if(*(spaths + i) < smallestvalue)
      {
        smallestvalue = *(spaths + i);
        smallestindex = i;
      }
    }
  }
  return smallestindex;
}

int main(int argc, char const *argv[]) {
  /* paths */
  /*   2 B  5   D  2   */
  /* A   3  2,3  3    F */
  /*   3 C  2   E   2  */

  //Create a 2d map
  int paths[6][6]     = { {0, 2, 3, 0, 0, 0},
                          {0, 0, 3, 5, 4, 0},
                          {0, 0, 3, 2, 3, 0},
                          {0, 0, 0, 0, 3, 2},
                          {0, 0, 0, 0, 0, 2},
                          {0, 0, 0, 0, 0, 0}};

  int spaths[6]       = {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
  bool svisited[6]    = {false, false, false, false, false, false};

  while (NotAllVisited(&svisited[0])) {
    //find the smallest
    int smallest = FindSmallest(&spaths[0], &svisited[0]);

    //set the smallest as visited
    svisited[smallest] = true;

    //run the real algo
    for(int j = 0; j < 6; j++)
    {
      if(paths[smallest][j] > 0)
      {
        if((spaths[smallest] + paths[smallest][j]) < spaths[j])
        {
          spaths[j] = spaths[smallest] + paths[smallest][j];
        }
      }
    }

  }

  cout<<"smallest path is "<<spaths[5]<<endl;
  return 0;
}

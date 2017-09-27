#include <iostream>
#include <vector>
using namespace std;
int noentry[5][5] = { {0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0}};

bool printpath(int arry[4][4], vector< pair <int,int> > path, int x, int y)
{
  if(x < 0 || y < 0 || x > 3 || y > 3)
   return false;

 if(x == 3 && y == 3)
 {
  //path found
  pair<int, int> temp = make_pair(x,y);
  path.push_back(temp);
   for(int i = 0; i < path.size(); i++)
   {
      pair<int, int> temp = path[i];
      cout<<"("<<temp.first<<","<<temp.second<<")"<<endl;
   }
   return true;
 }

 //check is spot free
 if(arry[x][y] == 0)
 {

   pair<int, int> temp = make_pair(x,y);
   path.push_back(temp);
   bool foundright = printpath(arry, path, x, y + 1);
   if(foundright == true)
    return true;
   bool founddown = printpath(arry, path, x + 1, y);
   if(founddown == true)
    return true;

   return false;
 }
 else
    return false;
}
int main()
{
  int arry[4][4] = { {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {0, 1, 1, 1},
                     {0, 0, 0, 0}};

  vector< pair<int,int> > path;
  printpath(arry, path, 0, 0);
}

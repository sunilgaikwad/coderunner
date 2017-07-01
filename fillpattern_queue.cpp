#include <iostream>
#include <queue>

using namespace std;

int M = 5;
int N = 6;

bool outofbounds(int x, int y)
{
  if(x < 0 || x >= M)
   return true;

   if(y < 0 || y >= N)
    return true;

  return false;
}

int main(int args, const char *argv[])
{
   //Create the fill
   bool mazerunner[5][6] = {{true,  true,  true,  true,  false, false},
                      { true,  true,  false, true,  false, false},
                      { true,  false, false, false,  true,  false},
                      { true,  true,  true,  false, true,  false},
                      { false, false, true,  true,  true,  false}};

   //push the first element in the queue
   typedef pair<int, int> vpair;
   queue<vpair> mazequeue;
   int x = 4;
   int y = 5;
   int vistedvertices = 0;

   //check to see if they are already visited
   //is it out of bounds
   if(!outofbounds(x, y))
   {
     if(mazerunner[x][y] == true)
     {
       cout<<"already visited. quiting program";
       return 0;
     }
     else
     {
       //set it to visited and push it on to the stack
       mazerunner[x][y] = true;
       mazequeue.push(make_pair(x, y));
     }
   }
   else
   {
     cout<<"Out of bound. quiting program";
     return 0;
   }

   //while the queue is not empty. process each element
   while(mazequeue.empty() == false)
   {
     vpair top = mazequeue.front();
     cout<<top.first<<" "<<top.second<<endl;
     mazequeue.pop();
     vistedvertices++;

     //Get the children and put them in queue if they are not already visited
     if(!outofbounds(top.first + 1, top.second) && mazerunner[top.first + 1][top.second] == false)
     {
       mazerunner[top.first + 1][top.second] = true;
       mazequeue.push(make_pair(top.first + 1, top.second));
     }
     if(!outofbounds(top.first - 1, top.second) && mazerunner[top.first - 1][top.second] == false)
     {
       mazerunner[top.first - 1][top.second] = true;
       mazequeue.push(make_pair(top.first - 1, top.second));
     }
     if(!outofbounds(top.first, top.second + 1) && mazerunner[top.first][top.second + 1] == false)
     {
       mazerunner[top.first][top.second + 1] = true;
       mazequeue.push(make_pair(top.first, top.second + 1));
     }
     if(!outofbounds(top.first, top.second - 1) && mazerunner[top.first][top.second - 1] == false)
     {
       mazerunner[top.first][top.second - 1] = true;
       mazequeue.push(make_pair(top.first, top.second - 1));
     }
   }
 cout<<"No of vertices visited " <<vistedvertices<<endl;
}

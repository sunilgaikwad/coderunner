#include <iostream>
#include <stack>

using namespace std;

int M = 5;
int N = 6;

int main(int args, const char *argv[])
{
   //Create the fill

   bool color[5][6] = {{true,  true,  true,  true,  false, false},
                      { true,  true,  false, true,  false, false},
                      { true,  false, false, false,  true,  false},
                      { true,  true,  true,  false, true,  false},
                      { false, false, true,  true,  true,  false}};


    typedef pair<int,int> ptpair;
    stack< pair<int,int> > pts;
    int x = 4;
    int y = 5;

    if((x >= 0 && x < M) && (y >= 0 && y < N))
    {
      if(color[x][y] == true)
      {
        cout<<"No of blocks filled "<<0<<endl;
        return 0;
      }
      else
        pts.push(make_pair(x, y));
    }
    else
    {
      cout<<"No of blocks filled "<<0<<endl;
      return 0;
    }

    int noofblocks = 0;

    while(pts.empty() != true)
    {
      ptpair temp = pts.top();
      pts.pop();

        //set the point as visited
        noofblocks++;
        color[temp.first][temp.second] = true;

        //push neighbours
        if((temp.first - 1 >= 0 && temp.first - 1 < M) && (temp.second >= 0 && temp.second < N))
        {
          if(color[temp.first - 1][temp.second] == false)
          {
            pts.push(make_pair(temp.first - 1, temp.second));
          }
        }
        if((temp.first + 1 >= 0 && temp.first + 1 < M) && (temp.second >= 0 && temp.second < N))
        {
          if(color[temp.first + 1][temp.second] == false)
          {
            pts.push(make_pair(temp.first + 1, temp.second));
          }
        }
        if((temp.first >= 0 && temp.first < M) && (temp.second - 1 >= 0 && temp.second - 1 < N))
        {
          if(color[temp.first][temp.second - 1] == false)
          {
            pts.push(make_pair(temp.first, temp.second - 1));
          }
        }
        if((temp.first >= 0 && temp.first < M) && (temp.second + 1 >= 0 && temp.second + 1 < N))
        {
          if(color[temp.first][temp.second + 1] == false)
          {
            pts.push(make_pair(temp.first, temp.second + 1));
          }
        }
    }

    cout<<"No of blocks filled "<<noofblocks<<endl;
    return 0;
}

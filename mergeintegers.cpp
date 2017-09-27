#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int mergenumbers(int x, int y)
{
  if(x > 100000000 || y > 100000000)
   return -1;

  //convert x into a vector
  int limit = 100000000;
  vector<int> vecx;
  for(int i = 0; i < 8; i++)
  {
    int temp = x/limit;
    if(temp == 0)
    {
      limit = limit/10;
    }
    else
    {
      vecx.push_back(temp);
      x = x - (limit * temp);
      limit = limit/10;
    }
  }
  //just one digit remaining so push it
  vecx.push_back(x);

  //convert y into a vector
  limit = 100000000;
  vector<int> vecy;
  for(int i = 0; i < 8; i++)
  {
    int temp = y/limit;
    if(temp == 0)
    {
      limit = limit/10;
    }
    else
    {
      vecy.push_back(temp);
      y = y - (limit * temp);
      limit = limit/10;
    }
  }
  //just one digit remaining so push it
  vecy.push_back(y);

  int result = 0;
  int sizex = vecx.size();
  int sizey = vecy.size();
  int ix = 0;
  int iy = 0;
  while(ix < sizex && iy < sizey)
  {
    result = (result * 10) + vecx[ix];
    result = (result * 10) + vecy[iy];
    ix++;
    iy++;
  }

  //if vecx has elemets
  while(ix < sizex)
  {
    result = (result * 10) + vecx[ix];
    ix++;
  }
  //if vecy has elements
  while(iy < sizey)
  {
    result = (result * 10) + vecy[iy];
    iy++;
  }

  if(result > 100000000)
   return -1;
  else
  return result;

}



int mergenumbersusingstd(int x, int y)
{
  if(x > 100000000 || y > 100000000)
   return -1;

  //convert x into a char array
  string sx = std::to_string(x);
  //convert y into a char array
  string sy = std::to_string(y);

  //just one digit remaining so push it
  string result = "";
  int sizex = sx.length();
  int sizey = sy.length();
  int ix = 0;
  int iy = 0;

  while(ix < sizex && iy < sizey)
  {
    result = result + sx[ix];
    result = result + sy[iy];
    ix++;
    iy++;
  }

  //if vecx has elemets
  while(ix < sizex)
  {
    result = result + sx[ix];
    ix++;
  }
  //if vecy has elements
  while(iy < sizey)
  {
    result = result + sy[iy];
    iy++;
  }

 //this is one method to convert integer to string
  //stringstream str(result);
  //int finalResult;
  //str>>finalResult;

  int finalResult = stoi(result);

  if(finalResult > 100000000)
   return -1;
  else
  return finalResult;

}

int main()
{
  int x = 123;
  int y = 5678;

  //int result = mergenumbers(x, y);
  int result = mergenumbersusingstd(x, y);
  if(result == -1)
  {
    cout<<"No too large";
  }
  else
  {
    cout<<result;
  }
}

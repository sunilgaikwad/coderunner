#include <iostream>
#include <vector>
using namespace std;

int climbsteps(int nsteps, vector<int> &vec)
{
  if(nsteps == 0)
   return 0;
  else if(nsteps == 1)
    return 1;
  else if(nsteps == 2)
      return 2;
  else if(nsteps == 3)
        return 4;
  else
  {


      if(vec[nsteps - 1] > 0)
       return vec[nsteps - 1];
      cout<<"calculating "<<nsteps<<endl;
      int result =  (climbsteps((nsteps - 1), vec) + climbsteps((nsteps - 2), vec) + climbsteps((nsteps - 3), vec));
      vec[nsteps - 1] = result;
  }
}

int main()
{
  int nsteps = 15;
  vector<int> vec(15, 0);
  int result = climbsteps(nsteps, vec);
  cout<<result;
}

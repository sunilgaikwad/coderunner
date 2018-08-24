#include <iostream>
#include <vector>
using namespace std;

void mergevectors(vector<int> &first, vector<int> &second)
{
  int sizefirst = first.size();
  int sizesecond = second.size();

  if(sizefirst == 0)
  {
    first = second;
    second.clear();
    return;
  }
  if(sizesecond == 0)
  {
    return;
  }


   for(int j = sizesecond - 1; j >= 0; j--)
   {
      int i = sizefirst - 1;
      if(i >= 0)
      {
         if(second[j] < first[i])
         {
            //swap
            int temp = second[j];
            second[j] = first[i];
            first[i] = temp;

            //check if the first vector's element is in the right place
            int k = i - 1;
            while(k >= 0 && first[k] > first[i])
            {
            int temp = first[k];
            first[k] = first[i];
            first[i] = temp;
            --k;
            --i;
            }
         }
      }
   }

}

template<class T>
void print(vector<T> vec1, vector<T> vec2)
{
  int size = vec1.size();
  for(int i = 0; i < size; i++)
    cout<<vec1[i]<<" ";
  cout<<endl;
  size = vec2.size();
  for(int i = 0; i < size; i++)
    cout<<vec2[i]<<" ";
}
int main()
{
  vector<int> first{4};
  vector<int> second{1, 5, 8, 12};

  mergevectors(first, second);
  print(first, second);
}

// you can use includes, for example:
// #include <algorithm>
#include <string>
#include <iostream>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
 size_t length = S.length();

 string result;
 int cnt = 0;
 int totalcnt = 0;
 for(size_t i = 0; i < length; i++)
 {
     if(S[i] >= '0' && S[i] <= '9')
     {
         cnt++;
         result = result + S[i];
         totalcnt++;
     }
     if((i != length - 1) && cnt == 3)
     {
         cnt = 0;
         result = result + '-';
         totalcnt++;
     }
 }
 if(cnt == 1)
 {
     char temp = result[totalcnt - 3];
     result[totalcnt - 3] = result[totalcnt - 2];
     result[totalcnt - 2] = temp;
 }
 return result;
}
int main()
{
  string s = "00-44  48 5555 8361";
 cout<<solution(s);
}

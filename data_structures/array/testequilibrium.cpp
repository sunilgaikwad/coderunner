// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
    long sum = 0;
    for(size_t i = 0; i < A.size(); i++)
    {
        sum = sum + A[i];
    }

    long left = A[0];
    long right = sum - A[0];
    long diff = abs(left - right);
    for(size_t i = 1; i < A.size() - 1; i++)
    {
        long tempdiff = abs((left + A[i]) - (right - A[i]));
        left = left + A[i];
        right = right - A[i];
        cout<<tempdiff<<endl;
        if(tempdiff < diff)
            diff = tempdiff;
    }
    return diff;
}

int main()
{
 vector<int> a{3, 5, 6, 1, 9};
 int result = solution(a);
 cout<<result;
}

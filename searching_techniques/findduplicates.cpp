#include <iostream>
#include <vector>

int findDuplicate(const std::vector<int> &input)
{
  size_t size = input.size();
  if(size <= 1)
    std:throw std::invalid_argument("Invalid input. Need atleast one duplicate");

  if(size == 2)
      return input[0];

  size_t start = 1;
  size_t end = size - 1;

  while(start <= end)
  {
    int mid = (end - start)/2 + start;

    size_t leftCnt = 0;
    size_t rightCnt = 0;
    for(size_t i = 0; i < size; i++)
    {
      if(input[i] >= start && input[i] <= mid)
      {
        leftCnt++;
      }
      if(input[i] >= mid + 1 && input[i] <= end)
      {
        rightCnt++;
      }
    }

    size_t aLeftCnt = mid - start + 1;
    size_t aRightCnt = end - (mid + 1) + 1;

    if(aLeftCnt == 1 && leftCnt > 1)
      return start;
    else if(aRightCnt == 1 && rightCnt > 1)
        return end;
    else if(aLeftCnt < leftCnt)
        end = mid;
    else
        start = mid + 1;
  }

  throw std::invalid_argument("No duplicates found");
}

int main()
{
  std::vector<int> input{1, 2, 3, 2};
  int result = findDuplicate(input);
  std::cout<<result;
}

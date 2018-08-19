#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int> &prices)
{
  int size = prices.size();
  if(size < 2)
   throw invalid_argument("Invalid input");

  int profit;
  int buy = 0; int sell = 1;
  int mprofit = prices[sell] - prices[buy];
  while(sell < size)
  {
    profit = prices[sell] - prices[buy];
    if(prices[buy] > prices[sell])
    {
      buy = sell;
      sell++;
    }
    else
    {
      sell++;
    }
    if(profit > mprofit)
     mprofit = profit;
  }
  return mprofit;
}

int main()
{
  vector<int> prices;
  prices.push_back(5);
  cout<<maxProfit(prices)<<endl;
}

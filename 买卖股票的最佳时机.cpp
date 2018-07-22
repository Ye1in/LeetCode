#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include <assert.h>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int result{};
        if (prices.empty())
            return 0;
        int minbuy = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            result = max(prices[i] - minbuy, result);
            minbuy = min(prices[i], minbuy);
        }
        return result;
    }
};
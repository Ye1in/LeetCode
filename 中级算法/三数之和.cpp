#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include <assert.h>
#include <queue>
using namespace std;
// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    vector<vector<int>> vv{};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
      if (i >= 1 && nums[i - 1] == nums[i])
        continue;
      for (int j = i + 1, k = n - 1; j < k;)
      {
        if (j > i + 1 && nums[j - 1] == nums[j])
        {
          ++j;
          continue;
        }
        if (k < n - 1 && nums[k] == nums[k + 1])
        {
          --k;
          continue;
        }
        int sum = nums[i] + nums[j] + nums[k];
        if (sum > 0)
          --k;
        else if (sum < 0)
          ++j;
        else
          vv.push_back(vector<int>{nums[i], nums[j++], nums[k--]});
      }
    }
    return vv;
  }
};

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
class Solution
{
  public:
    Solution(vector<int> nums) : init(nums)
    {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return init;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        vector<int> nums(init);
        // uniform_int_distribution<> d(0, nums.size() - 1);
        // knuth_b e;
        // for (int i = 0; i < nums.size(); ++i)
        // swap(nums[i], nums[d(e)]);
        for (int i = 0; i < nums.size(); ++i)
        {
            int t = i + rand() % (nums.size() - i);
            swap(nums[i], nums[t]);
        }
        return nums;
    }
    vector<int> init;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

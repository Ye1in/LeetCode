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
#include <math.h>
using namespace std;
// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

// 在杨辉三角中，每个数是它左上方和右上方的数的和。

// 示例:

// 输入: 5
// 输出:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vv{};
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> v(i + 1, 0);
            v.front() = 1;
            v.back() = 1;
            for (int j = 1; j < i; ++j)
                v[j] = vv[i - 1][j - 1] + vv[i - 1][j];
            vv.push_back(v);
        }
        return vv;
    }
};

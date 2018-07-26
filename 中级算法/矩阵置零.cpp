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
#include <utility>
using namespace std;
// 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

// 示例 1:

// 输入:
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// 输出:
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// 示例 2:

// 输入:
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// 输出:
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// 进阶:

// 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
// 你能想出一个常数空间的解决方案吗？
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> v{};
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                    v.push_back(make_pair(i, j));
            }
        }
        for (pair<int, int> var : v)
        {
            for (int m = 0; m < matrix[var.first].size(); ++m)
                matrix[var.first][m] = 0;
            for (int n = 0; n < matrix.size(); ++n)
                matrix[n][var.second] = 0;
        }
    }
};

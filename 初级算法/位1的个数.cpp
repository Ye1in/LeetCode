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
// 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

// 示例 :

// 输入: 11
// 输出: 3
// 解释: 整数 11 的二进制表示为 00000000000000000000000000001011

// 示例 2:

// 输入: 128
// 输出: 1
// 解释: 整数 128 的二进制表示为 00000000000000000000000010000000
class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        for (int i = 31; i >= 0; --i)
        {
            if (n >= pow(2, i))
            {
                n -= pow(2, i);
                ++count;
            }
        }
        return count;
    }
};
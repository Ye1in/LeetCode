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

// 颠倒给定的 32 位无符号整数的二进制位。

// 示例:

// 输入: 43261596
// 输出: 964176192
// 解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
//      返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
// 进阶:
// 如果多次调用这个函数，你将如何优化你的算法？
class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t t;
        for (int i = 0; i < 32; ++i)
        {
            t <<= 1;
            t = t | (n & 1);
            n >>= 1;
        }
        return t;
    }
};

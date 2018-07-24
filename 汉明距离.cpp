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
// 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

// 给出两个整数 x 和 y，计算它们之间的汉明距离。

// 注意：
// 0 ≤ x, y < 231.

// 示例:

// 输入: x = 1, y = 4

// 输出: 2

// 解释:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑

// 上面的箭头指出了对应二进制位不同的位置。
class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        int count = 0;
        for (int i = 31; i >= 0; --i)
        {
            if (x >= pow(2, i) && y >= pow(2, i))
            {
                x -= pow(2, i);
                y -= pow(2, i);
                continue;
            }
            if (x >= pow(2, i) || y >= pow(2, i))
            {
                if (x > y)
                {
                    x -= pow(2, i);
                    ++count;
                }
                else
                {
                    y -= pow(2, i);
                    ++count;
                }
            }
        }
        return count;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);

        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
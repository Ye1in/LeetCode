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
// 给定一个整数，写一个函数来判断它是否是 3 的幂次方。

// 示例 1:

// 输入: 27
// 输出: true
// 示例 2:

// 输入: 0
// 输出: false
// 示例 3:

// 输入: 9
// 输出: true
// 示例 4:

// 输入: 45
// 输出: false
// 进阶：
// 你能不使用循环或者递归来完成本题吗？
class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        return (n > 0 && 1162261467 % n == 0);
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int n = stringToInteger(line);

        bool ret = Solution().isPowerOfThree(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
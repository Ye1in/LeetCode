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
// 统计所有小于非负整数 n 的质数的数量。

// 示例:

// 输入: 10
// 输出: 4
// 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
class Solution
{
  public:
    int countPrimes(int n)
    {
        if (n <= 1)
            return 0;
        vector<bool> prime(n, true);
        for (int i = 2; i * i < n; ++i)
        {
            if (!prime[i])
                continue;
            for (int j = 2; j * i < n; ++j)
                prime[j * i] = false;
        }
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (prime[i])
                count++;
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
        int n = stringToInteger(line);

        int ret = Solution().countPrimes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
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
#include <set>
using namespace std;
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

// 示例 1：

// 输入: "babad"
// 输出: "bab"
// 注意: "aba"也是一个有效答案。
// 示例 2：

// 输入: "cbbd"
// 输出: "bb"
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.empty() || s.size() == 1)
            return s;
        string longeststring{};
        int tf[1000][1000]{}, l = s.size();
        for (int i = 0; i < l - 1; ++i)
        {
            tf[i][i] = 1;
            longeststring = s.substr(i, 1);
            if (s.at(i) == s.at(i + 1))
            {
                tf[i][i + 1] = 1;
                longeststring = s.substr(i, 2);
            }
        }
        tf[l - 1][l - 1] = 1;
        for (int n = 3; n < l; ++n)
        {
            for (int i = 0; i + n - 1 < l; ++i)
            {
                int j = i + n - 1;
                if (s.at(i) == s.at(j) && tf[i + 1][j - 1])
                {
                    tf[i][j] = 1;
                    longeststring = s.substr(i, j - i + 1);
                }
            }
        }
        return longeststring;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
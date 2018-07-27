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

// 给定一个字符串，找出不含有重复字符的最长子串的长度。

// 示例：

// 给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

// 给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

// 给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, n = 0, l = s.size();
        set<char> st{};
        while (i < l && j < l)
        {
            if (st.insert(s.at(j)).second)
            {
                ++j;
                n = std::max(n, j - i);
            }
            else
                st.erase(s.at(i++));
        }
        return n;
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
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
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

// 示例:

// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result{};
        if (digits.size() == 0)
            return result;
        string str{};
        letterCombinations(digits, str, 0, result);
        return result;
    }
    void letterCombinations(string digits, string &str, int index, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(str);
            return;
        }
        string base[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < base[digits[index] - '0'].size(); ++i)
        {
            str += base[digits[index] - '0'][i];
            letterCombinations(digits, str, index + 1, result);
            str.pop_back();
        }
    }
};

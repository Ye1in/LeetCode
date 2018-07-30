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
// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
class Solution
{
  public:
    void generateParenthesis(int left, int right, string str, vector<string> &result)
    {
        if (left > right)
            return;
        if (left == 0 && right == 0)
            result.push_back(str);
        else
        {
            if (left > 0)
                generateParenthesis(left - 1, right, str + '(', result);
            if (right > 0)
                generateParenthesis(left, right - 1, str + ')', result);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result{};
        if (n == 0)
            return result;
        string str{};
        generateParenthesis(n, n, str, result);
        return result;
    }
};

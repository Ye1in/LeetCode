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
#include <stack>
using namespace std;
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:

// 输入: "()"
// 输出: true
// 示例 2:

// 输入: "()[]{}"
// 输出: true
// 示例 3:

// 输入: "(]"
// 输出: false
// 示例 4:

// 输入: "([)]"
// 输出: false
// 示例 5:

// 输入: "{[]}"
// 输出: true
class Solution
{
  public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> sq{};
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s.at(i))
            {
            case '(':
                sq.push('(');
                break;
            case '[':
                sq.push('[');
                break;
            case '{':
                sq.push('{');
                break;
            case ')':
                if (!sq.empty())
                    if (sq.top() == '(')
                    {
                        sq.pop();
                        break;
                    }
                return false;
            case ']':
                if (!sq.empty())
                    if (sq.top() == '[')
                    {
                        sq.pop();
                        break;
                    }
                return false;
            case '}':
                if (!sq.empty())
                    if (sq.top() == '{')
                    {
                        sq.pop();
                        break;
                    }
                return false;
            }
        }
        if (sq.empty())
            return true;
        return false;
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        bool ret = Solution().isValid(s);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
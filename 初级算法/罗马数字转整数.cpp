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
// 罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。

// 字符          数值
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
// 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

// 示例 1:

// 输入: "III"
// 输出: 3
// 示例 2:

// 输入: "IV"
// 输出: 4
// 示例 3:

// 输入: "IX"
// 输出: 9
// 示例 4:

// 输入: "LVIII"
// 输出: 58
// 解释: C = 100, L = 50, XXX = 30, III = 3.
// 示例 5:

// 输入: "MCMXCIV"
// 输出: 1994
// 解释: M = 1000, CM = 900, XC = 90, IV = 4.
class Solution
{
  public:
    int romanToInt(string s)
    {
        int total = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            switch (s.at(i))
            {
            case 'I':
                if (i == s.size() - 1)
                {
                    total += 1;
                    break;
                }
                if (s.at(i + 1) == 'V')
                {
                    total += 4;
                    ++i;
                    break;
                }
                if (s.at(i + 1) == 'X')
                {
                    total += 9;
                    ++i;
                    break;
                }
                total += 1;
                break;
            case 'V':
                total += 5;
                break;
            case 'X':
                if (i == s.size() - 1)
                {
                    total += 10;
                    break;
                }
                if (s.at(i + 1) == 'L')
                {
                    total += 40;
                    ++i;
                    break;
                }
                if (s.at(i + 1) == 'C')
                {
                    total += 90;
                    ++i;
                    break;
                }
                total += 10;
                break;
            case 'L':
                total += 50;
                break;
            case 'C':
                if (i == s.size() - 1)
                {
                    total += 100;
                    break;
                }
                if (s.at(i + 1) == 'D')
                {
                    total += 400;
                    ++i;
                    break;
                }
                if (s.at(i + 1) == 'M')
                {
                    total += 900;
                    ++i;
                    break;
                }
                total += 100;
                break;
            case 'D':
                total += 500;
                break;
            case 'M':
                total += 1000;
                break;
            }
        }
        return total;
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

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
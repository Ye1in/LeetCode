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

// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：

// 所有输入均为小写字母。
// 不考虑答案输出的顺序。
class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    map<multiset<char>, int> mp{};
    int num = 0;
    vector<vector<string>> temp{};
    for (int i = 0; i < strs.size(); ++i)
    {
      multiset<char> ms{};
      for (int j = 0; j < strs[i].size(); ++j)
        ms.insert(static_cast<char>(strs[i][j]));
      if (mp.find(ms) == mp.end())
      {
        mp.insert({ms, num});
        temp.push_back(vector<string>());
        temp[num++].push_back(strs[i]);
      }
      else
      {
        temp[mp.find(ms)->second].push_back(strs[i]);
      }
    }
    return temp;
  }
};

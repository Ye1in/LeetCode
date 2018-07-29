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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> vv{};
        queue<TreeNode *> que{};
        que.push(root);
        int revers = 0;
        while (!que.empty())
        {
            int n = que.size();
            vector<int> v{};
            while (--n)
            {
                TreeNode *temp = que.front();
                que.pop();
                v.push_back(temp->val);
                if (temp->left)
                    que.push(temp->left);
                if (temp->right)
                    que.push(temp->right);
            }
            if (revers % 2 == 1)
                reverse(v.begin(), v.end());
            ++revers;
            vv.push_back(v);
        }
        return vv;
    }
};

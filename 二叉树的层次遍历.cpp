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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vv{};
        if (root==NULL)
            return vv;
        queue<TreeNode *> que;
        que.push(root);
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
            vv.push_back(v);
        }
        // reverse(vv.begin(), vv.end());
        return vv;
    }
};
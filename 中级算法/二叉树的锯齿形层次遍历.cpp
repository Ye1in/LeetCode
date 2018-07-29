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
    // vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    // {
    //     vector<vector<int>> vv{};
    //     queue<TreeNode *> que{};
    //     que.push(root);
    //     bool revers = false;
    //     while (!que.empty())
    //     {
    //         int n = que.size();
    //         vector<int> v{};
    //         while (--n)
    //         {
    //             TreeNode *temp = que.front();
    //             que.pop();
    //             v.push_back(temp->val);
    //             if (temp->left)
    //                 que.push(temp->left);
    //             if (temp->right)
    //                 que.push(temp->right);
    //         }
    //         if (revers)
    //             reverse(v.begin(), v.end());
    //         revers = !revers;
    //         vv.push_back(v);
    //     }
    //     return vv;
    // }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> vv{};
        if (!root)
            return vv;
        bool left = true;
        stack<TreeNode *> leftstack{}, rightstack{};
        leftstack.push(root);
        while (!leftstack.empty() || !rightstack.empty())
        {
            if (left)
            {
                int n = leftstack.size();
                vector<int> v{};
                while (n--)
                {
                    TreeNode *temp = leftstack.top();
                    leftstack.pop();
                    v.push_back(temp->val);
                    if (temp->left)
                        rightstack.push(temp->left);
                    if (temp->right)
                        rightstack.push(temp->right);
                }
                vv.push_back(v);
            }
            else
            {
                int n = rightstack.size();
                vector<int> v{};
                while (n--)
                {
                    TreeNode *temp = rightstack.top();
                    rightstack.pop();
                    v.push_back(temp->val);
                    if (temp->right)
                        leftstack.push(temp->right);
                    if (temp->left)
                        leftstack.push(temp->left);
                }
                vv.push_back(v);
            }
            left = !left;
        }
        return vv;
    }
};

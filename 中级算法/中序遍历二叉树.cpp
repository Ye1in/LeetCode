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
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 给定一个二叉树，返回它的中序 遍历。

// 示例:

// 输入: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// 输出: [1,3,2]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
// class Solution
// {
//   public:
//     void inorderTraversal(TreeNode *root, vector<int> &v)
//     {
//         if (!root)
//             return;
//         if (root->left)
//             inorderTraversal(root->left, v);
//         v.push_back(root->val);
//         if (root->right)
//             inorderTraversal(root->right, v);
//     }
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> temp{};
//         inorderTraversal(root, temp);
//         return temp;
//     }
// };
迭代
class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st{};
        vector<int> temp{};
        TreeNode *p = root;
        TreeNode *t = NULL;
        while (p || !st.empty())
        {
            if (p)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                t = st.top();
                st.pop();
                temp.push_back(t->val);
                p = t->right;
            }
        }
        return temp;
    }
};
// Non-recursion and no stack
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode *root) {
//         vector<int> res;
//         if (!root) return res;
//         TreeNode *cur, *pre;
//         cur = root;
//         while (cur) {
//             if (!cur->left) {
//                 res.push_back(cur->val);
//                 cur = cur->right;
//             } else {
//                 pre = cur->left;
//                 while (pre->right && pre->right != cur) pre = pre->right;
//                 if (!pre->right) {
//                     pre->right = cur;
//                     cur = cur->left;
//                 } else {
//                     pre->right = NULL;
//                     res.push_back(cur->val);
//                     cur = cur->right;
//                 }
//             }
//         }
//         return res;
//     }
// };

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        TreeNode *root = stringToTreeNode(line);

        vector<int> ret = Solution().inorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
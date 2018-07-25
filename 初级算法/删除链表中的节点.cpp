#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include <assert.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
  public:
    void deleteNode(ListNode *node)
    {
        if (node == NULL || node->next == NULL)
            return;
        node->val = node->next->val;
        ListNode *tmp = node->next;
        node->next = tmp->next;
        delete tmp;
    }
};
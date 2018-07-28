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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 编写一个程序，找到两个单链表相交的起始节点。

// 例如，下面的两个链表：

// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
// 在节点 c1 开始相交。

// 注意：

// 如果两个链表没有交点，返回 null.
// 在返回结果后，两个链表仍须保持原有的结构。
// 可假定整个链表结构中没有循环。
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

// 致谢:
// 特别感谢 @stellari 添加此问题并创建所有测试用例。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        int lenA = 0, lenB = 0;
        ListNode *itA = headA, *itB = headB;
        while (itA->next)
        {
            ++lenA;
            itA = itA->next;
        }
        while (itB->next)
        {
            ++lenB;
            itB = itB->next;
        }
        if (itA != itB)
            return NULL;
        int len = lenA - lenB;
        if (len >= 0)
        {
            while (len > 0)
            {
                headA = headA->next;
                --len;
            }
            while (headA)
            {
                if (headA == headB)
                    return headA;
                headA = headA->next;
                headB = headB->next;
            }
        }
        if (len < 0)
        {
            while (len < 0)
            {
                headB = headB->next;
                ++len;
            }
            while (headB)
            {
                if (headA == headB)
                    return headB;
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};

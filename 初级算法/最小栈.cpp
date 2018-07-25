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

// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) -- 将元素 x 推入栈中。
// pop() -- 删除栈顶的元素。
// top() -- 获取栈顶元素。
// getMin() -- 检索栈中的最小元素。
// 示例:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.

class MinStack
{
  public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        l.push_back(x);
    }

    void pop()
    {
        if (!l.empty())
            l.pop_back();
    }

    int top()
    {
        if (!l.empty())
            return l.back();
        else
            return NULL;
    }

    int getMin()
    {
        int min = INT_MAX;

        for (int x : l)
        {
            if (x < min)
                min = x;
        }
        return min;
    }
    list<int> l;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

/*
https://www.geeksforgeeks.org/dsa/queue-using-stacks/

232. Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=problem-list-v2&envId=queue&utm_source=chatgpt.com

*/

class MyQueue
{
    stack<int> s1, s2;
    int size;

public:
    MyQueue()
    {
        size = 0;
    }

    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        size++;
    }

    int pop()
    {
        int val = s1.top();
        s1.pop();
        size--;
        return val;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
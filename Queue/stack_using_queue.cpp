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
225. Implement Stack using Queues

https://leetcode.com/problems/implement-stack-using-queues/description/?envType=problem-list-v2&envId=queue&utm_source=chatgpt.com
*/
class MyStack
{
    queue<int> q;
    int size;

public:
    MyStack()
    {
        size = 0;
    }

    void push(int x)
    {
        q.push(x);
        size++;
        for (int i = 0; i < size - 1; i++)
        {
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        size--;
        return val;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return size == 0;
    }

    void show()
    {
        cout<<"Current Queue: ";
        queue<int> temp=q;
        while (!temp.empty())
        {
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
        
    }
};


int main()
{
    MyStack *obj=new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->show();

}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
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
#include <climits>
using namespace std;

/*
Queue Reversal without extra space

https://www.geeksforgeeks.org/problems/queue-reversal/1

*/
class Solution
{
public:
   void reverseQueue(queue<int> &q)
    {
        // code here
           if(q.empty()) return;

            int val = q.front();
            q.pop();
            reverseQueue(q);

            q.push(val);
        
    }
    void show(queue<int> &q)
    {
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
    }
};

int main()
{
    Solution s1;
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    s1.reverseQueue(q);

    s1.show(q);
}
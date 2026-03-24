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
933. Number of Recent Calls
https://leetcode.com/problems/number-of-recent-calls/description/

*/


class RecentCounter {
    queue<int> q;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front()<t-3000)
        {
            q.pop();
        }
        
        return q.size();
        
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{
}
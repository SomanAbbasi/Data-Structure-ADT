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
2073. Time Needed to Buy Tickets

https://leetcode.com/problems/time-needed-to-buy-tickets/description/

*/
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {

        queue<pair<int, int>> q;
        int ln=tickets.size();

        for (int i = 0; i < ln; i++)
        {
            q.push({tickets[i], i});
        }
        int time=0;

        while (!q.empty())
        {
            auto[t,idx]=q.front();
            q.pop();
            t--;
            time++;
            if(t==0 && idx==k) return time;

            if(t>0)
                q.push({t,idx});
        }
        

        return time;

    }
};

int main()
{
}
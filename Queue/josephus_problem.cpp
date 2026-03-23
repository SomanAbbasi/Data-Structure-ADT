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

1823. Find the Winner of the Circular Game

https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

*/


class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        while (q.size()>1)
        {
            // remove k-1 person to the back
            for (int i = 1; i < k; i++)
            {
                int val=q.front();
                q.pop();
                q.push(val);
            }
            //remove kth person
            q.pop();
            
        }
        


        return q.front();
        
    }
};



int main()
{
   
}
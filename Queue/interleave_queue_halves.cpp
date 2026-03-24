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

Interleave the First Half of the Queue with Second Half

https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

*/

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();

        int mid=n/2;

        queue<int> firstHalf;

        for (int i = 0; i < mid; i++)
        {
            firstHalf.push(q.front());
            q.pop();
        }

        while (!firstHalf.empty())
        {
            
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
        
        
        
    }
};

int main()
{
}
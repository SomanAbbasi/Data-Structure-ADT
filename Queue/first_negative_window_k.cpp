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

First negative in every window of size k

https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

*/

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {

        vector<int> res;
        queue<int> q;
        int ln = arr.size();

        for (int i = 0; i < k; i++)
        {
            if (arr[i] < 0)
                q.push(i);
        }

        for (int i = k; i < ln; i++)
        {
            // for prev window
            if (!q.empty())
            {
                res.push_back(arr[q.front()]);
            }
            else
            {
                res.push_back(0);
            }

            // remove elements out of window
            while (!q.empty() && q.front() <= i - k)
            {
                q.pop();
            }

            if (arr[i] < 0)
            {
                q.push(i);
            }
        }

        // for last window
        if (!q.empty())
        {
            res.push_back(arr[q.front()]);
        }
        else
        {
            res.push_back(0);
        }

        return res;
    }
};

int main()
{
}
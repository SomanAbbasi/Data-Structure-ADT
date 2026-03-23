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

239. Sliding Window Maximum

https://leetcode.com/problems/sliding-window-maximum/?envType=problem-list-v2&envId=queue&utm_source=chatgpt.com
*/
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
           deque<int> dq; 
        vector<int> res;
        int ln=nums.size();
        for (int i = 0; i < ln; i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        for (int num : res)
        {
            cout << num << " ";
        }
        cout << endl;

        return res;
    }
};

int main()
{
    Solution s1;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    s1.maxSlidingWindow(nums, 3);
}
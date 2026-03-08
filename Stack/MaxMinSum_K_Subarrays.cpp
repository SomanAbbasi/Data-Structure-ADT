

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include<algorithm>

using namespace std;

/*
3430. Maximum and Minimum Sums of at Most Size K Subarrays
https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subarrays/description/



*/

class Solution
{
public:

    long long countValid(long long L, long long R, int k)
    {
        long long total = 0;

        for(long long l = 1; l <= L; l++)
        {
            long long r = min(R, (long long)k + 1 - l);

            if(r <= 0) break;

            total += r;
        }

        return total;
    }

    long long solve(vector<int>& nums, int k, bool isMin)
    {
        int n = nums.size();

        vector<int> left(n), right(n);

        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() &&
                 (isMin ? nums[st.top()] > nums[i]
                        : nums[st.top()] < nums[i]))
            {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() &&
                 (isMin ? nums[st.top()] >= nums[i]
                        : nums[st.top()] <= nums[i]))
            {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            long long L = i - left[i];
            long long R = right[i] - i;

            long long cnt = countValid(L, R, k);

            ans += cnt * nums[i];
        }

        return ans;
    }

    long long minMaxSubarraySum(vector<int>& nums, int k)
    {
        long long minSum = solve(nums, k, true);

        long long maxSum = solve(nums, k, false);

        return minSum + maxSum;
    }
};


int main()
{
}
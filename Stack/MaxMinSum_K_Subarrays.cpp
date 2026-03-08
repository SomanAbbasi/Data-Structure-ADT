

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

class Solution {
public:
using ll = long long int;
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll ans = 0;
        {
            vector<int> psi(n,-1),nsi(n,n);
            stack<int> st;

            for(int i=0;i<n;i++) {
                while(st.size() and nums[st.top()]>=nums[i]) {
                    nsi[st.top()]=i;
                    st.pop();
                }

                if(st.size())
                psi[i] = st.top();

                st.push(i);
            }

            for(int i=0;i<n;i++) {
                ll l = max(psi[i],i-k);
                ll r = min(nsi[i],i+k);

                ll mnd = min(i-l,r-i);
                ll mxd = max(i-l,r-i);

                ans+=mnd*(mnd+1)/2*nums[i];
                ans+=(min(mnd+mxd-1,1LL*k)-mnd)*mnd*nums[i];
                ll diff = min(mnd+mxd-1,1LL*k)-mxd;
                ans-=diff*(diff+1)/2*nums[i];
            }
        }

        
        {
            vector<int> pgi(n,-1),ngi(n,n);
            stack<int> st;

            for(int i=0;i<n;i++) {
                while(st.size() and nums[st.top()]<=nums[i]) {
                    ngi[st.top()]=i;
                    st.pop();
                }

                if(st.size())
                pgi[i] = st.top();

                st.push(i);
            }

            for(int i=0;i<n;i++) {
                ll l = max(pgi[i],i-k);
                ll r = min(ngi[i],i+k);

                ll mnd = min(i-l,r-i);
                ll mxd = max(i-l,r-i);

                ans+=mnd*(mnd+1)/2*nums[i];
                ans+=(min(mnd+mxd-1,1LL*k)-mnd)*mnd*nums[i];
                ll diff = min(mnd+mxd-1,1LL*k)-mxd;
                ans-=diff*(diff+1)/2*nums[i];
            }
        }
        return ans;
    }
};



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
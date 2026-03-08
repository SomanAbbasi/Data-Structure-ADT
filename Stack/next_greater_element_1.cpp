
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;
/*

496. Next Greater Element I

https://leetcode.com/problems/next-greater-element-i/


Disclamier:
    we can Optimized it By Unordered_map


*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        vector<int> res;

        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;

        for (int i = 0; i < n2; i++)
        {
            if (st.empty())
            {
                st.push(i);
                continue;
            }
            while (!st.empty() && nums2[st.top()] < nums2[i])
            {
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            mp[nums2[st.top()]] = -1;
            st.pop();
        }



        for (auto num : nums1)
        {
            res.push_back(mp[num]);
        }

       // printRes(res);

        return res;
    }

    void printRes(vector<int> arr)
    {
        for (auto num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s1;
    vector<int> arr1 = {4, 1, 2};
    vector<int> arr2 = {1, 3, 4, 2};
    s1.nextGreaterElement(arr1, arr2);
}
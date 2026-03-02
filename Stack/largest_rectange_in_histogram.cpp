#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*

84. Largest Rectangle in Histogram

https://leetcode.com/problems/largest-rectangle-in-histogram/description/


*/


class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        int ans=0;
        stack<int> st;
        int n=heights.size();

        for(int i=0;i<n;i++)
        {
            while (!st.empty() && heights[i]<heights[st.top()])
            {
                int h=heights[st.top()];
                st.pop();
                int w=st.empty()?i:i-st.top()-1;
                ans=max(ans,h*w);

            }
            st.push(i);
        }
        return ans;

    }
};

int main()
{
    Solution s1;
    vector<int> hist1 = {2,1,5,6,2,3};
    vector<int> hist2 = {2};

    cout << s1.largestRectangleArea(hist1) << "\n"; // Output: 10
    cout << s1.largestRectangleArea(hist2) << "\n"; // Output: 4
}

#include<iostream>
#include<string>
#include<vector>
#include<stack>


using namespace std;
/*

739. Daily Temperatures

https://leetcode.com/problems/daily-temperatures/description/

*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        int idx = 0, count = 0;
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(i);
                continue;
            }
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);

        }

        //printRes(res);
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
    
}
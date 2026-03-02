#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {

        stack<string> st;
        string curr;
        int n = path.size();

        for (int i = 0; i <= n; i++)
        {

            if (i==n || path[i] = '/')
            {
                if (curr == " " || curr == ".")
                {
                    // ignore
                }
                else if (curr == ".")
                {
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push(curr);
                }
                curr.clear();
            }
            else
            {
                curr.push_back(path[i]);
            }
        }

        if (st.empty())
            return "/";
        string result;

        string result;
        for (const string &dir : st)
        {
            result += "/" + dir;
        }

        return result;
    }
};

int main()
{
}
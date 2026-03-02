#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


/*

71. Simplify Path

https://leetcode.com/problems/simplify-path/description/

*/
class Solution
{
public:
    string simplifyPath(string path)
    {

        vector<string> st;
        string curr;
        int n = path.size();

        for (int i = 0; i < n; i++)
        {
            // skip consecutive slashes /
            while (i < n && path[i] == '/')
            {
                i += 1;
            }
            if (i >= n)
                break;
            int j = i;
            while (j < n && path[j] != '/')
            {
                j += 1;
            }

            string part = path.substr(i, j - i);
            if (part == "..")
            {
                if (!st.empty())
                {
                    st.pop_back();
                }
            }
            else if (part != ".")
            {
                st.push_back(part);
            }
            i = j;
        }

        if (st.empty())
            return "/";

        string res;

        for (auto dir : st)
        {
            res += "/" + dir;
        }

        return res;
    }
};

int main()
{

    Solution s1;

    cout << s1.simplifyPath("/home//foo/") << "\n"; 
    cout << s1.simplifyPath("/.../a/../b/c/../d/./") << "\n"; 
    cout << s1.simplifyPath("/../") << "\n"; // /
}
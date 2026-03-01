#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


/*

1021. Remove Outermost Parentheses
https://leetcode.com/problems/remove-outermost-parentheses/description/

*/
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string result;
        int count = 0;

        bool flag = true;
        for (char ch : s)
        {
            if (ch == '(')
            {
                if (count > 0)
                    result.push_back(ch);
                count += 1;
            }
            else
            {
                count -= 1;

                if (count > 0)
                    result.push_back(ch);
            }
        }

        return result;
    }
};

int main()
{

    Solution s1;

    cout << "Example 1 Output: " << s1.removeOuterParentheses("(()())(())") << endl;
    cout << "Example 2 Output: " << s1.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << "Example 3 Output: " << s1.removeOuterParentheses("()()") << endl;
}
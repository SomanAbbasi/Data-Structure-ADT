#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


/*

402. Remove K Digits

https://leetcode.com/problems/remove-k-digits/description/
*/
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string result;

        for (char ch : num)
        {
            while (!result.empty() && k > 0 && result.back() > ch)
            {
                result.pop_back();
                k -= 1;
            }
            if (result.empty())
            {
                if (ch != '0')
                    result.push_back(ch);
            }
            else
            {
                result.push_back(ch);
            }
        }

        while (!result.empty() && k > 0)
        {
            result.pop_back();
            k -= 1;
        }

        return  !result.empty()?result:"0";
    }
};

int main()
{
    Solution s1;

    cout << "Example 1 Output: " << s1.removeKdigits("1432219", 3) << endl;
    cout << "Example 2 Output: " << s1.removeKdigits("10200", 1) << endl;
    cout << "Example 3 Output: " << s1.removeKdigits("10", 2) << endl;
}
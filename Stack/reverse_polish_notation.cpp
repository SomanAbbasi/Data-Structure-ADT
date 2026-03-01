#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


/*


150. Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


*/
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string token : tokens)
        {
            if (token == "+" || token == "-" || token == "/" || token == "*")
            {
                int b= st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (token == "+")
                {
                    st.push(a + b);
                }
                else if (token == "-")
                {
                    st.push(a - b);
                }
                else if (token == "*")
                {
                    st.push(a * b);
                }
                else
                {
                    st.push(a / b);
                }
            }
            else{
                st.push(stoi(token));

            }

        
        }

        return st.top();

    }
};

int main()
{
    Solution s1;
    // Example 1
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Output: " << s1.evalRPN(tokens1) << endl; // 9

    // Example 2
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Output: " << s1.evalRPN(tokens2) << endl; // 6

    // Example 3
    vector<string> tokens3 = {
        "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << "Output: " << s1.evalRPN(tokens3) << endl; // 22
}

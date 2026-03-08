#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*

Postfix to Prefix Conversion
https://www.geeksforgeeks.org/dsa/postfix-prefix-conversion/
*/

/*
Methods:
    => Scan the postfix expression from left to right.
    => For each character:
        => If it’s an operand, push it onto the stack.
        => If it’s an operator, pop the top two operands,
        combine them as operator + operand1 + operand2, and push back.
    At the end, the stack contains the full prefix expression.
*/

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(string postfix)
{
    stack<string> st;

    for (char ch : postfix)
    {
        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else if (isOperator(ch))
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string expr = ch + op1 + op2;
            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string postfix = "AB+C*";
    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << postfixToPrefix(postfix) << endl;
}
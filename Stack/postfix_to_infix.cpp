#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*

Postfix to Infix

https://www.geeksforgeeks.org/dsa/postfix-to-infix/

*/

/*
Methods:
    =>Scan the postfix expression from left to right.
    => For each character:
        => If it’s an operand, push it onto the stack.
        => If it’s an operator, pop the top two operands from the stack,
        combine them as (operand1 operator operand2), and push back.
    At the end, the stack will contain the full infix expression.
*/

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix)
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
            // Pop two operands
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string postfix = "AB+C*";
    cout << "Postfix: " << postfix << endl;
    cout << "Infix: " << postfixToInfix(postfix) << endl;
}
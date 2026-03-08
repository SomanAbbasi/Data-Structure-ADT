#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*

Prefix to Infix

https://www.geeksforgeeks.org/dsa/prefix-infix-conversion/
*/

/*
Methods:
    =>Scan the prefix expression from right to left.
    => For each character:
        => If it’s an operand, push it onto the stack.
        => If it’s an operator, pop the top two operands from the stack,
        combine them as (operand1 operator operand2), and push back.
        Note: pop first gives operand1, pop second gives operand2.
    At the end, the stack will contain the full infix expression.
*/

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToInfix(string prefix)
{
    stack<string> st;

    int n=prefix.size();

    for (int i = n-1; i>=0; i--)
    {
        char ch=prefix[i];
        if(isalnum(ch))
        {
            st.push(string(1,ch));
        }
        else if(isOperator(ch))
        {
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string expr="("+op1+ch+op2+")";
            st.push(expr);

        }
    }
    

    return st.top();
}

int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << "Prefix: " << prefix << endl;
    cout << "Infix: " << prefixToInfix(prefix) << endl;
}
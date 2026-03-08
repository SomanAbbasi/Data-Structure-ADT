#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
Infix to Postfix Expression

https://www.geeksforgeeks.org/dsa/convert-infix-expression-to-postfix-expression/

*/

/*

Methods:
Initialize an empty stack for operators and an empty string for postfix output.
Traverse from left to right:

    => If operand → append to output.
    => If '(' → push to stack.
    => If ')' → pop and append until '(' is found. Pop '(' but don’t append.
    => if operator:
        => While stack is not empty, and operator on top has higher or equal precedence (for left-associative)
        or higher precedence (for right-associative), pop from stack to output.
        => Push current operator onto stack.

    => After scanning, pop any remaining operators from stack to output.

*/

// Function to return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Function to check if operator is right associative
bool isRightAssociative(char op)
{
    return op == '^';
}
// Function to convert infix to postfix

string infixToPostfix(string infix)
{
    stack<char> st;
    string postFix = "";

    for (char ch : infix)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            postFix += ch; // Operand → append
        }
        else if (ch == '(')
        {
            st.push(ch); // Left parenthesis → push
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(') // append until '(' is found.
            {
                postFix += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Pop '('
        }
        else // Operator
        {
            while (!st.empty() && ((isRightAssociative(ch) && precedence(ch) < precedence(st.top())) || (!isRightAssociative(ch) && precedence(ch) <= precedence(st.top()))) && st.top() != '(')
            {
                postFix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        postFix += st.top();
        st.pop();
    }

    return postFix;
}

int main()
{

    string s1 = "A^B^C";
    string s2 = "A+B*C";

    cout << infixToPostfix(s1) << endl;
    cout << infixToPostfix(s2) << endl;
}
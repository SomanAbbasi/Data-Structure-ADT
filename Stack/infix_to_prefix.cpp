#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

/*
Infix To Prefix Notation

https://www.geeksforgeeks.org/dsa/convert-infix-prefix-notation/


Disclamier:

Note: Prefix = reverse( s( reverse(infix) ) )
Method:
    => First, we reverse the infix expression because prefix is evaluated from right to left (opposite of s).
    => While reversing, we swap '(' with ')' to maintain the correct grouping of subexpressions.
    => Now, we convert this modified expression into s using the standard stack-based method.
Finally, we reverse the resulting s expression. This gives the correct prefix form.

*/

// function to return precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if operator is right-associative
bool isRightAssociative(char op)
{
    return (op == '^');
}

// function to convert infix to prefix
string infixToPrefix(string s)
{

    // reverse the string
    reverse(s.begin(), s.end());

    // swap '(' and ')'
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    stack<char> st;
    string result = "";

    // convert to postfix (on reversed expression)
    for (int i = 0; i < (int)s.length(); i++)
    {
        char c = s[i];

        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && st.top() != '(' &&
                   ((precedence(st.top()) > precedence(c)) ||
                    (precedence(st.top()) == precedence(c) && isRightAssociative(c))))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop all remaining operators
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    // reverse the result to prefix
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string s = "a*(b+c)/d";
    cout << infixToPrefix(s);
    return 0;
}

int main()
{
    string expr = "(A-B/C)*(A/K-L)";
    cout << "Prefix: " << infixToPrefix(expr) << endl;
}
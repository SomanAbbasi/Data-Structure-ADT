

/*

1106. Parsing A Boolean Expression
https://leetcode.com/problems/parsing-a-boolean-expression/

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;

        for (char ch : expression)
        {
            if (ch == ',' || ch == '(')
                continue;
            else if (ch == ')')

            {
                bool isFalse = false;
                bool isTrue = false;
                while (st.top() != '&' && st.top() != '|' && st.top() != '!')
                {
                    char s = st.top();
                    if (s == 't')
                        isTrue = true;
                    else if (s == 'f')
                        isFalse = true;
                    st.pop();
                }
                char op = st.top();
                st.pop();

                if (op == '&')
                {
                    if (isFalse)
                    {
                        st.push('f');
                    }
                    else
                    {
                        st.push('t');
                    }
                }
                else if (op == '|')
                {
                    if (isTrue)
                    {
                        st.push('t');
                    }
                    else
                    {
                        st.push('f');
                    }
                }
                else
                {
                    if (isTrue)
                    {
                        st.push('f');
                    }
                    else
                    {
                        st.push('t');
                    }
                }
            }
            else
            {
                st.push(ch);
            }
        }

        return st.top() == 't';
    }
};

int main()
{

    Solution s;

    cout << (s.parseBoolExpr("&(|(f))") ? "True" : "False") << "\n";
    cout << (s.parseBoolExpr("|(f,f,f,t)") ? "True" : "False") << "\n";
    cout << (s.parseBoolExpr("!(&(t,f))") ? "True" : "False") << "\n";
}
/*
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',') continue;

            if (ch != ')') {
                st.push(ch);
            } else {
                // collect operands inside current parentheses
                vector<char> operands;
                while (!st.empty() && st.top() != '(') {
                    operands.push_back(st.top());
                    st.pop();
                }

                st.pop(); // remove '('

                char op = st.top(); st.pop(); // operator for this subexpression

                char res;
                if (op == '!') {
                    res = (operands[0] == 't') ? 'f' : 't';
                } else if (op == '&') {
                    res = 't';
                    for (char v : operands) {
                        if (v == 'f') { res = 'f'; break; }
                    }
                } else { // '|'
                    res = 'f';
                    for (char v : operands) {
                        if (v == 't') { res = 't'; break; }
                    }
                }

                st.push(res); // push result back
            }
        }

        return st.top() == 't';
    }
};

int main() {
    Solution s;

    cout << (s.parseBoolExpr("!(f)") ? "True" : "False") << "\n";
    cout << (s.parseBoolExpr("|(f,f,f,t)") ? "True" : "False") << "\n";
    cout << (s.parseBoolExpr("&(t,|(f,t),!(f))") ? "True" : "False") << "\n";
    cout << (s.parseBoolExpr("!(&(t,f))") ? "True" : "False") << "\n";
}

*/

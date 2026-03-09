
#include<iostream>
#include<stack>

using namespace std;


void insertSorted(stack<int> &st,int x)
{

    if(st.empty() || st.top()<=x)
    {
            st.push(x);
            return;
    }
    int temp=st.top();
    st.pop();
    insertSorted(st,x);

    st.push(temp);
    
}

void sortStack(stack<int> &st)
{
    if(st.empty())
        return;
    int x=st.top();
    st.pop();

    //sort remaining stack
    sortStack(st);

    //insert pop element correctly

    insertSorted(st,x);

}

int main()
{
    stack<int> st;

    st.push(4);
    st.push(2);
    st.push(3);
    st.push(1);

    sortStack(st);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
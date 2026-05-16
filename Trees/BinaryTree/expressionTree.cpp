#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*

https://www.geeksforgeeks.org/dsa/expression-tree/
*/

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool isOperand(char c)
{
    return isalnum(c); // A-Z, a-z , 0-9
}

// Build Tree From PostFix expression
Node *expressionTree(string postfix)
{
    stack<Node *> st;

    for (char ch : postfix)
    {
        // if operand push node
        if (isOperand(ch))
        {
            st.push(new Node(ch));
        }
        else
        {
            // pop two nodes
            Node *right = st.top();
            st.pop();
            Node *left = st.top();
            st.pop();

            Node *newNode = new Node(ch);
            newNode->left = left;
            newNode->right = right;

            st.push(newNode);
        }
    }

    return st.top();
}

// A+B
void inorderTraversal(Node *root)
{
    if (!root)
        return;
    if (!isOperand(root->data))
        cout << "(";

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
    if (!isOperand(root->data))
        cout << ")";
}
// +AB
void preorderTraversal(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// AB+
void postorderTraversal(Node *root)
{
    if (!root)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// level orde Traversal

void levelorderTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();

        while (levelSize--)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
      //  cout << endl;
    }
}

void deleteTree(Node *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    string postfix = "ABC*+";

    Node *root = expressionTree(postfix);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "PreOrder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";

    postorderTraversal(root);
    cout << endl;

    cout << "level by level traversal: ";

    levelorderTraversal(root);

    cout << endl;

    cout << "Deleting Tree: ";
    deleteTree(root);
}

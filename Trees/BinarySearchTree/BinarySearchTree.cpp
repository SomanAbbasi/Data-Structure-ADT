#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/
*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create new Node
Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// To insert a Node in BST
Node *insertNode(Node *root, int data)
{
    /*If the tree is empty, return a new node*/
    if (root == nullptr)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// In order Traversal
/*
=> Traverse the left subtree
=> Visit the root node
=> Traverse the right subtree
Left → Root → Right (LNR).

*/

void preorderTraversal(Node *root)
{
    if (root)
    {
        cout << root->data << " ";

        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}
// search a given value in a given BST
Node *searchNode(Node *root, int value)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == value)
    {
        return root;
    }
    // value is gretaer than traverse right
    if (root->data < value)
    {
        return searchNode(root->right, value);
    }
    // value is smaller than traverse right
    return searchNode(root->left, value);
}

// min value
Node *minValueNode(Node *node)
{
    Node *current = node;
    // loop down to find leftmost
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

Node* maxValueNode(Node* node)
{
    Node* current=node;

    // move to rightmost node
    while(current && current->right!=nullptr)
    {
        current=current->right;
    }

    return current;
}

// deleteNode

/*
=> Deleting a leaf node.
=> Deleting a node having single child.
=> Deletion a node having both children.

Steps:
=> If a target node is leaf node, simply delete it
=> If a target node has 1 child,
replace the target node with its child node and delete the target node.
=> If a target node has 2 children
Find the target node's inorder successor or Predecessor.
Replace the target node with successor or Predecessor.
Delete the inorder successor or Predecessor.
*/
Node *deleteNode(Node *root, int data)
{
    if (root == nullptr)
        return root;
    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    // if data is same as root's data, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder Predecessor
        // (smallest in the right subtree)

        Node *temp = maxValueNode(root->left);
        // Copy the inorder Predecessor's content to this node
        root->data = temp->data;

        // Delete the inorder Predecessor

        root->left = deleteNode(root->left, temp->data);
    }
    return root;
}

int main()
{

    Node *root = nullptr;
    // create a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search "
            "Tree is: ";
    inorderTraversal(root);
    cout << endl;

    // delete a node in BST
    root = deleteNode(root, 20);
    cout << "After deletion of 20: ";
    inorderTraversal(root);
    cout << endl;

    // Insert a node in BST
    root = insertNode(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout << endl;

    // Search a key in BST
    Node *found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr)
    {
        cout << "Node 25 found in the BST." << endl;
    }
    else
    {
        cout << "Node 25 not found in the BST." << endl;
    }
}

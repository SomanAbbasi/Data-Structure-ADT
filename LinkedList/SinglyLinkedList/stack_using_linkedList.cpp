#include <iostream>
using namespace std;




/*

https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/
*/
class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* topNode;

public:
    // Constructor
    Stack() {
        topNode = nullptr;
    }

    // Push operation
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop operation
    void pop() {
        if (topNode == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Top operation
    int top() {
        if (topNode == nullptr) {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    // Check if empty
    bool empty() {
        return topNode == nullptr;
    }

    // Utility: print stack
    void print() {
        Node* temp = topNode;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
};
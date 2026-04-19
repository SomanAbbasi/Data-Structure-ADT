#include <iostream>
using namespace std;


/*

https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
*/
class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int x) : data(x), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;

public:
    // Constructor
    Queue() {
        frontNode = rearNode = nullptr;
    }

    // Enqueue
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rearNode == nullptr) {
            // Empty queue
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Dequeue
    void dequeue() {
        if (frontNode == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        // If queue becomes empty
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
    }

    // Peek front
    int front() {
        if (frontNode == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return frontNode->data;
    }

    // Check empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Print queue
    void print() {
        Node* temp = frontNode;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
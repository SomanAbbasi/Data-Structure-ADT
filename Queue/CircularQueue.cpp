#include<iostream>
using namespace std;

/*
Concept
Instead of shifting, rear wraps around.

rear = (rear + 1) % capacity

Example:

capacity = 5

10 20 30 40 50

After removing 3 elements:

_ _ _ 40 50

New insertion:

60 goes to index 0

Queue becomes

60 _ _ 40 50
Full Condition:

 => (rear + 1) % capacity == front

*/

class CircularQueue {

private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:

    CircularQueue(int size) {

        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int x) {

        if (isFull()) {
            cout << "Queue Full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = x;
    }

    int dequeue() {

        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }

        int val = arr[front];

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        return val;
    }

    int getFront() {

        if (isEmpty())
            return -1;

        return arr[front];
    }
};

int main()
{
    
}
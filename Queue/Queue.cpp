#include<iostream>
using namespace std;

#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;      // dynamic array
    int front;     // index of front element
    int rear;      // index of rear element
    int capacity;  // maximum size

public:

    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Insert element
    void enqueue(int x) {

        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    // Remove element
    int dequeue() {

        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int removed = arr[front];
        front++;

        return removed;
    }

    // Get front element
    int getFront() {

        if (isEmpty())
            return -1;

        return arr[front];
    }

    // Size
    int size() {

        if (isEmpty())
            return 0;

        return rear - front + 1;
    }

    // Display queue
    void display() {

        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{

}
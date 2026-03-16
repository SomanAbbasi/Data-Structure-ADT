#include<iostream>
using namespace std;

/*
Shifted Queue (Linear Queue with Shifting)
Concept:
When queue reaches end but front > 0, we shift elements left.

Example:

Before shift

_ _ _ 40 50
front=3 rear=4

After shift

40 50 _ _ _
front=0 rear=1

Now we can insert more.
*/


class ShiftedQueue {

private:
    int *arr;
    int front;
    int rear;
    int capacity;

public:

    ShiftedQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    // Shift elements
    void shiftElements() {

        int j = 0;

        for (int i = front; i <= rear; i++)
            arr[j++] = arr[i];

        rear = rear - front;
        front = 0;
    }

    void enqueue(int x) {

        if (isFull()) {

            if (front > 0)
                shiftElements();
            else {
                cout << "Queue Full\n";
                return;
            }
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    int dequeue() {

        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front++];
    }
};



int main()
{

}
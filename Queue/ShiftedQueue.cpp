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



/*

ADT of shifted Queue


*/

class ShiftedQueue
{
private:
    int *arr;
    int front;
    int rear;
    int capacity;

    // Resize function
    void resize()
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        // Copy valid elements
        int size = rear - front + 1;
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[front + i];
        }

        // Reset pointers
        front = 0;
        rear = size - 1;

        // Replace old array
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    // shift all elements to left
    void helper()
    {

        int size = rear - front + 1;
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr[front + i];
        }
        front = 0;
        rear = size - 1;
    }

public:
    ShiftedQueue(int size = 4)
    {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    ~ShiftedQueue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return (rear < front);
    }

    bool isFull()
    {
        return (rear == capacity - 1);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            if (front > 0)
            {
                helper();
            }
            else
            {
                resize();
            }
        }
        rear++;
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ShiftedQueue q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.enqueue(4);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(5);
    q.enqueue(6);

    q.display();
}
      
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


/*

https://leetcode.com/problems/design-circular-queue/description/
*/
class MyCircularQueue
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k)
    {
        capacity = k;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;

        rear = (rear+1) % capacity;
        arr[rear] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;

        size--;

        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    int Rear()
    {
         if (isEmpty())
            return -1;
        return arr[rear];

    }

    bool isEmpty()
    {
        if(size==0)
            return true;
        return false;
    }

    bool isFull()
    {
        if(size==capacity)
            return true;
        return false;
    }

    ~MyCircularQueue() {
        delete[] arr;
    }
};

int main()
{
    
}
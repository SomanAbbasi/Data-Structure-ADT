#include<iostream>

using namespace std;

/*

https://leetcode.com/problems/design-circular-deque/submissions/1953851483/

*/

class MyCircularDeque
{
    int *arr;
    int capacity;
    int front;
    int rear;

public:
    MyCircularDeque(int k)
    {
        capacity = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;

        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear = (rear - 1 + capacity) % capacity;
        }
        return true;
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

    int size()
    {
        if(isEmpty()) return 0;
        if(rear>=front)
        {
            return rear-front+1;
        }
        else{
            return capacity-front+rear+1;
        }
    }
    bool isEmpty()
    {
        return front==-1;
    }

    bool isFull()
    {
        return ((rear+1)%capacity)==front;
        
    }
};
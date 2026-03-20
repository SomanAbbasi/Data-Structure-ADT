#include<iostream>

using namespace std;

/*

https://leetcode.com/problems/design-circular-deque/submissions/1953851483/

*/

class MyCircularDeque
{

    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        capacity = k;
        arr = new int[capacity];
        front = 0;
        rear = k-1;
        size = 0;
    }

    bool insertFront(int value)
    {
        if(isFull())
            return false;
        
        front=(front-1+capacity)%capacity;
        arr[front]=value;
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if(isFull())
            return false;
        rear=(rear+1)%capacity;
        arr[rear]=value;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if(isEmpty())
            return false;
        front=(front+1)%capacity;
        size--;
        return true;
    }

    bool deleteLast()
    {
        if(isEmpty())
            return false;
        rear=(rear-1+capacity)%capacity;
        size--;

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

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (size == capacity)
            return true;
        return false;
    }
};
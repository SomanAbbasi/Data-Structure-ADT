#include <iostream>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/priority-queue-set-1-introduction/
*/
class PriorityQueue
{
private:
    int *arr;
    int capacity;
    int size;

public:
    PriorityQueue(int k)
    {
        capacity = k;
        arr = new int[k];
        size = 0;
    }

    bool insert(int value)
    {
        if (size == capacity)
            return false;

        int i = size - 1;
        // Shift element to right
        while (i >= 0 && arr[i] < value)
        {
            arr[i + 1] = arr[i];
            i -= 1;
        }
        arr[i + 1] = value;
        size++;
        return true;
    }

    bool removeMax()
    {
        if (size == 0)
            return false;

        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size -= 1;
        return true;
    }

    int getMax()
    {
        if (size == 0)
            return -1;
        return arr[0];
    }
    int size()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    ~PriorityQueue()
    {
        delete[] arr;
    }
};

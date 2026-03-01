#pragma once

#include <stdexcept>
using namespace std;
template <typename T>
class Stack
{
private:
    T *stack;
    int capacity;
    int topIndex;

    void resize(int newCapacity)
    {
        T *newData = new T[newCapacity];

        for (int i = 0; i <= topIndex; ++i)
        {
            newData[i] = stack[i];
        }

        delete[] stack;
        stack = newData;
        capacity = newCapacity;
    }

public:
    Stack(int cap = 10000)
        : capacity(cap), topIndex(-1)
    {

        if (capacity <= 0)
        {
            throw invalid_argument("Capacity must be positive");
        }

        stack = new T[capacity];
    }

    // Copy constructor
    Stack(const Stack &other)
        : capacity(other.capacity), topIndex(other.topIndex)
    {

        stack = new T[capacity];
        for (int i = 0; i <= topIndex; ++i)
        {
            stack[i] = other.stack[i];
        }
    }

    // Copy assignment
    Stack &operator=(const Stack &other)
    {
        if (this == &other)
            return *this;

        delete[] stack;

        capacity = other.capacity;
        topIndex = other.topIndex;
        stack = new T[capacity];

        for (int i = 0; i <= topIndex; ++i)
        {
            stack[i] = other.stack[i];
        }

        return *this;
    }

    // Destructor
    ~Stack()
    {
        delete[] stack;
    }

    void push(const T &value)
    {
        if (isFull())
        {
            resize(capacity * 2); // expand
        }
        stack[++topIndex] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack Underflow");
        }
        --topIndex;
    }

    T top() const
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty");
        }
        return stack[topIndex];
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    bool isFull() const
    {
        return topIndex == capacity - 1;
    }

    int size() const
    {
        return topIndex + 1;
    }

    int getCapacity() const
    {
        return capacity;
    }
};
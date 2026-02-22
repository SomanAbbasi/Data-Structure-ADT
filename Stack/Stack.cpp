#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack
{
private:
    T *data;
    int capacity;
    int topIndex;

public:
    Stack(int cap)
    {
        if (cap <= 0)
        {
            throw std::invalid_argument("Capacity must be greater than 0");
        }
        capacity = cap;
        topIndex = -1;
        data = new T[capacity];
    }

    // Destructor
    ~Stack()
    {
        delete[] data;
    }

    void push(const T &value)
    {
        if (isFull())
        {
            throw overflow_error("Stack Overflow");
        }
        data[++topIndex] = value;
    }

    T pop()
    {
        if (isEmpty())
        {
            throw underflow_error("Stack Underflow");
        }
        return data[topIndex--];
    }

    T top() const
    {
        if (isEmpty())
        {
            throw underflow_error("Stack is empty");
        }
        return data[topIndex];
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
};

void testStack()
{
    cout << "Running Stack Tests...\n";

    try
    {
        Stack<int> s(3);

        // Test 1: Empty stack
        if (!s.isEmpty())
        {
           cout << "Test Failed: Stack should be empty\n";
            return;
        }

        // Test 2: Push elements
        s.push(10);
        s.push(20);
        s.push(30);

        if (s.size() != 3 || s.top() != 30)
        {
            cout << "Test Failed: Push or Top incorrect\n";
            return;
        }

        
        try
        {
            s.push(40);
            cout << "Test Failed: Overflow not detected\n";
            return;
        }
        catch (const overflow_error &)
        {
           cout << "Overflow test passed\n";
        }

        // Test 4: Pop elements
        if (s.pop() != 30 || s.pop() != 20 || s.pop() != 10)
        {
           cout << "Test Failed: Pop incorrect\n";
            return;
        }

        // Test 5: Underflow
        try
        {
            s.pop();
            cout << "Test Failed: Underflow not detected\n";
            return;
        }
        catch (const underflow_error &)
        {
            cout << "Underflow test passed\n";
        }

        // Test 6: Top on empty stack
        try
        {
            s.top();
           cout << "Test Failed: Top on empty stack not detected\n";
            return;
        }
        catch (const underflow_error &)
        {
            cout << "Top-on-empty test passed\n";
        }

        cout << "All Stack tests passed successfully.\n";
    }
    catch (const exception &e)
    {
        cout << "Unexpected error: " << e.what() << "\n";
    }
}

int main()
{
    testStack();
    return 0;
}
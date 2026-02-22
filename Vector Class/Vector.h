#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <initializer_list>

using namespace std;

template <typename T>
class Vector
{
private:
    T* arr;
    int Size;
    int Capacity;

    void expand(int newCapacity)
    {
        try
        {
            T* tempArr = new T[newCapacity];
            for (int i = 0; i < Size; i++)
                tempArr[i] = arr[i];

            delete[] arr;
            arr = tempArr;
            Capacity = newCapacity;
        }
        catch (...)
        {
            throw runtime_error("Memory allocation failed");
        }
    }

public:
    Vector()
    {
        arr = nullptr;
        Size = 0;
        Capacity = 0;
    }

    Vector(int cap)
    {
        Size = 0;
        Capacity = cap;
        arr = new T[cap];
    }

    // Initializer list constructor
    Vector(initializer_list<T> list)
    {
        Size = list.size();
        Capacity = Size;
        arr = new T[Capacity];

        int i = 0;
        for (auto val : list)
            arr[i++] = val;
    }

    ~Vector()
    {
        delete[] arr;
    }

    void push_back(T value)
    {
        try
        {
            if (Size == Capacity)
            {
                int newCap = (Capacity == 0) ? 1 : Capacity * 2;
                expand(newCap);
            }
            arr[Size++] = value;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    void pop_back()
    {
        if (Size == 0)
            throw runtime_error("Vector is empty");
        Size--;
    }

    T get(int index) const
    {
        if (index < 0 || index >= Size)
            throw out_of_range("Index out of range");
        return arr[index];
    }

    void set(int index, T value)
    {
        if (index < 0 || index >= Size)
            throw out_of_range("Index out of range");
        arr[index] = value;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= Size)
            throw out_of_range("Index out of range");
        return arr[index];
    }

    int size() const
    {
        return Size;
    }

    int capacity() const
    {
        return Capacity;
    }

    bool empty() const
    {
        return Size == 0;
    }

    void reserve(int newCapacity)
    {
        try
        {
            if (newCapacity > Capacity)
                expand(newCapacity);
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    void resize(int newSize)
    {
        try
        {
            if (newSize > Capacity)
                expand(newSize);

            for (int i = Size; i < newSize; i++)
                arr[i] = T();

            Size = newSize;
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
    }

    void clear()
    {
        Size = 0;
    }

    void display() const
    {
        for (int i = 0; i < Size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    T minElement() const
    {
        if (Size == 0)
            throw runtime_error("Vector is empty");

        T minVal = arr[0];
        for (int i = 1; i < Size; i++)
            if (arr[i] < minVal)
                minVal = arr[i];

        return minVal;
    }

    T maxElement() const
    {
        if (Size == 0)
            throw runtime_error("Vector is empty");

        T maxVal = arr[0];
        for (int i = 1; i < Size; i++)
            if (arr[i] > maxVal)
                maxVal = arr[i];

        return maxVal;
    }

    void sortVector()
    {
        sort(arr, arr + Size);
    }
};




/*
#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;
template <typename T>

class Vector

{
private:
    T *arr;
    int Size;
    int Capacity;

public:
    Vector()
    {
        arr = nullptr;
        Size = 0;
        Capacity = 0;
    }
    Vector(int cap)
    {
        Size = 0;
        Capacity = cap;
        arr = new T[cap];
    }
    ~Vector()
    {
        delete[] arr;
    }

    void expand(int newCapacity)
    {
        T *tempArr = new T[newCapacity];
        for (int i = 0; i < Size; i++)
        {
            tempArr[i] = arr[i];
        }
        delete[] arr;
        arr = tempArr;
        Capacity = newCapacity;
    }

    void push_back(T value)
    {
        try
        {
            if (Size == Capacity)
            {
                int newCap = (Capacity == 0) ? 1 : Capacity * 2;
                expand(newCap);
            }
            arr[Size++] = value;
        }
        catch (...)
        {
            cout << "Error while inserting element\n";
        }
    }

    void pop_back()
    {

        if (Size == 0)
        {
            cout << "Vector is empty.\n";
        }
        else
        {
            Size -= 1;
        }
    }
    T get(int index) const
    {
        if (index < 0 || index >= Size)
        {
            cout << "Index out of range\n";
        }
        else
        {
            return arr[index];
        }
    }

    void set(int index, T value)
    {
        if (index < 0 || index >= Size)
        {
            cout << "Index out of range\n";
        }
        else
        {
            arr[index] = value;
        }
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= Size)
        {
            cout << "Index out of range\n";
        }
        else
        {
            return arr[index];
        }
    }

    int size() const
    {
        return Size;
    }

    int capacity()
    {
        return Capacity;
    }
    bool empty() const
    {
        return Size == 0;
    }

    void reserve(int newCapacity)
    {
        try
        {
            if (newCapacity > Capacity)
                expand(newCapacity);
        }
        catch (...)
        {
            cout << "Reserve failed\n";
        }
    }

    void resize(int newSize)
    {
        try
        {
            if (newSize > Capacity)
            {
                expand(newSize);
            }
            for (int i = Size; i < newSize; i++)
            {
                arr[i] = T();
            }
            Size = newSize;
        }
        catch (...)
        {
            cout << "Resize failed\n";
        }
    }

    void clear()
    {
        Size = 0;
    }
    void display() const
    {
        for (int i = 0; i < Size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T minElement() const
    {
        try
        {
            if (Size == 0)
                throw runtime_error("Vector is empty");

            T minVal = arr[0];
            for (int i = 1; i < Size; i++)
                if (arr[i] < minVal)
                    minVal = arr[i];

            return minVal;
        }
        catch (exception &e)
        {
            cout << e.what() << std::endl;
            return T();
        }
    }
    T maxElement() const
    {
        try
        {
            if (Size == 0)
                throw runtime_error("Vector is empty");

            T maxVal = arr[0];
            for (int i = 1; i < Size; i++)
                if (arr[i] > maxVal)
                    maxVal = arr[i];

            return maxVal;
        }
        catch (exception &e)
        {
            cout << e.what() << std::endl;
            return T();
        }
    }

    void sortVector()
    {

        sort(arr, arr + Size);
        /*
         void selectionSort()
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < SIZE; j++)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            if (minIdx != i)
            {
                std::swap(arr[i], arr[minIdx]);
            }
        }
    }
 
 
    */
/*
    }
};

int main()
{
    Vector<int> v1;


    // v1.minElement();
    v1.push_back(20);
    v1.push_back(10);
    v1.display();
    v1.sortVector();
    v1.display();
}

*/
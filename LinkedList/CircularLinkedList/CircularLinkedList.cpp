#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/circular-linked-list/

*/

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;
    Node *tail;
    int listSize;

public:
    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    // insert Head
    void insertHead(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            // maintain circle
            tail->next = head;
        }
        listSize++;
    }
    // insertTail
    void insertTail(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;

            tail->next = head;
        }

        listSize++;
    }

    // insert at
    void insertAt(int index, int val)
    {
        if (index < 0 || index > listSize)
        {
            cout << "Invalid Index\n";
            return;
        }

        if (index == 0)
        {
            insertHead(val);
            return;
        }

        if (index == listSize)
        {
            insertTail(val);
            return;
        }
        Node *temp = head;

        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        listSize++;
    }
    // delete head

    void deleteHead()
    {
        if (!head)
            return;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        listSize--;
    }
    // delte tail
    void deleteTail()
    {
        if (!head)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;

            while (temp->next != tail)
                temp = temp->next;

            temp->next = head;

            delete tail;
            tail = temp;
        }

        listSize--;
    }

    // delte at index

    void deleteAt(int index)
    {
        if (index < 0 || index >= listSize)
        {
            cout << "Invalid Index\n";
            return;
        }

        if (index == 0)
        {
            deleteHead();
            return;
        }

        if (index == listSize - 1)
        {
            deleteTail();
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
        listSize--;
    }

    // search
    bool search(int val)
    {
        if (!head)
            return false;

        Node *temp = head;

        do
        {
            if (temp->data == val)
                return true;

            temp = temp->next;

        } while (temp != head);

        return false;
    }

    // display
    void display()
    {
        if (!head)
        {
            cout << "List Empty\n";
            return;
        }

        Node *temp = head;

        cout << "CLL: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != head);

        cout << endl;
    }

    // reverse Circular linked list
    void reverse()
    {
        if (!head || head == tail)
            return;

        Node *prev = tail;
        Node *curr = head;
        Node *nextNode;
        do
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;

        } while (curr != head);

        Node *temp = head;
        head = tail;
        tail = temp;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
    int size()
    {
        return listSize;
    }

    ~CircularLinkedList()
    {
        while (head)
            deleteHead();
    }
};

int main()
{


}

#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/introduction-to-circular-doubly-linked-list/
*/

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }
};

class CircularDoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int listSize;

public:
    CircularDoublyLinkedList()
    {
        head = tail = nullptr;
        listSize = 0;
    }

    // insert head
    void insertHead(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;

            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;

            head->prev = newNode;
            tail->next = newNode;

            head = newNode;
        }
        listSize++;
    }
    // insert tail
    void insertTail(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;

            head->next = head;
            head->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;

            tail->next = newNode;
            head->prev = newNode;

            tail = newNode;
        }
        listSize++;
    }

    void insertAt(int index, int val)
    {
        if (index < 0 || index > listSize)
        {
            cout << "Invalid index\n";
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

        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        listSize++;
    }

    // delte Head
    void deleteHead()
    {
        if (!head)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            listSize--;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
        listSize--;
    }
    // delte Tail

    void deleteTail()
    {
        if (!head)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            listSize--;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        listSize--;
    }
    void deleteAt(int index)
    {
        if (index < 0 || index >= listSize || !head)
        {
            cout << "Invalid index\n";
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

        for (int i = 0; i < index; i++)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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

    //reverse
    void reverse()
    {
        if (!head || head == tail)
            return;

        Node *curr = head;
        do
        {
            Node *temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = temp;

        } while (curr != head);
        Node *temp = head;
        head = tail;
        tail = temp;
    }

    //display forward
    void displayForward()
    {
        if (!head)
        {
            cout << "Empty List\n";
            return;
        }

        Node *temp = head;

        cout << "Forward: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }

    // Display Backward
    void displayBackward()
    {
        if (!tail)
            return;

        Node *temp = tail;

        cout << "Backward: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);

        cout << "(back to tail)\n";
    }
};

int main()
{
    
}
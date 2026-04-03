#include <iostream>
using namespace std;

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

class SinglyLinkedList
{
private:
    Node *head;
    int listSize;

public:
    // Constructor
    SinglyLinkedList()
    {
        head = nullptr;
        listSize = 0;
    }

    // Insert at Front
    void insertHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        listSize++;
    }

    // Insert at End
    void insertTail(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
        listSize++;
    }

    // Insert at position
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

        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        listSize++;
    }

    // Delete Head
    void deleteHead()
    {
        if (!head)
            return;

        Node *temp = head;
        head = head->next;
        delete temp;
        listSize--;
    }

    // Delete Tail
    void deleteTail()
    {
        if (!head)
            return;

        if (!head->next)
        { // single node
            delete head;
            head = nullptr;
            listSize--;
            return;
        }

        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        listSize--;
    }

    // Delete at index
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

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        listSize--;
    }

    // Search
    bool search(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Size
    int getSize()
    {
        return listSize;
    }

    // Reverse
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        Node *nxt = nullptr;

        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head = prev;
    }

    // Display
    void display()
    {
        if (!head)
        {
            cout << "Linked List is empty\n";
            return;
        }

        Node *temp = head;
        cout << "List: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList list;

    list.insertTail(10);
    list.insertTail(20);
    list.insertHead(5);
    list.insertAt(1, 7); // 5 7 10 20

    list.display();
    cout << "Size: " << list.getSize() << "\n";

    list.deleteAt(2); // delete 10
    list.display();   // 5 7 20

    list.deleteHead();
    list.display(); // 7 20

    list.deleteTail();
    list.display(); // 7

    cout << "Search 20: " << list.search(20) << "\n";

    list.reverse();
    list.display();
}
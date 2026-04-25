#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;

struct DLLNode
{
    int data;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DLLNode *head;
    DLLNode *tail;
    int listSize;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    // Insert At head

    void insertHead(int val)
    {
        DLLNode *newNode = new DLLNode(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    // Insert At Tail
    void insertTail(int val)
    {
        DLLNode *newNode = new DLLNode(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    // Insert At Index
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

        DLLNode *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        DLLNode *newNode = new DLLNode(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
        listSize++;
    }

    // deleteHead
    void deleteHead()
    {
        if (!head)
            return;

        // handle single node
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            DLLNode *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }

        listSize--;
    }

    // deleteTail
    void deleteTail()
    {
        if (!tail)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            DLLNode *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }

        listSize--;
    }

    // delete at
    void deleteAt(int index)
    {
        if (index < 0 || index >= listSize)
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

        DLLNode *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        listSize--;
    }

    // search a value
    bool search(int val)
    {
        DLLNode *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }

        return false;
    }

    // getsize
    int Size()
    {
        return listSize;
    }

    // Reverse DLL
    void reverse()
    {
        if (!head || !head->next)
            return;
        DLLNode *curr = head;
        DLLNode *temp = nullptr;
        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }

    // Display Forward
    void displayForward()
    {
        if (!head)
        {
            cout << "List Empty\n";
            return;
        }

        cout << "Forward: ";

        DLLNode *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // DisplayBackward
    void displayBackward()
    {
        if (!tail)
        {
            cout << "List Empty\n";
            return;
        }

        cout << "Backward: ";

        DLLNode *temp = tail;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
    ~DoublyLinkedList()
    {
        while (head)
            deleteHead();
    }
};

int main()
{

    DoublyLinkedList list;

    list.insertTail(10);
    list.insertTail(20);
    list.insertHead(5);
    list.insertAt(1, 7);

    // 5 7 10 20
    list.displayForward();
    list.displayBackward();

    cout << "Size: " << list.Size() << endl;

    list.deleteAt(2); // remove 10
    list.displayForward();

    list.deleteHead();
    list.displayForward();

    list.deleteTail();
    list.displayForward();

    cout << "Search 20: "
         << (list.search(20) ? "Found" : "Not Found")
         << endl;

    list.insertTail(30);
    list.insertTail(40);

    list.displayForward();

    list.reverse();

    cout << "After Reverse:\n";
    list.displayForward();
    list.displayBackward();
}
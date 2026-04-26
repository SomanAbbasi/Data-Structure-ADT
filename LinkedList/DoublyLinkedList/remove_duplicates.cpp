
#include <iostream>
#include <unordered_set>
using namespace std;

/*
https://www.geeksforgeeks.org/dsa/remove-duplicates-unsorted-doubly-linked-list/

*/

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

Node *removeDuplicates(Node *head) {
    unordered_set<int> hashSet;
    Node *curr = head;

    while (curr != nullptr) {

        // Check if the element is already in the hash table
        if (hashSet.find(curr->data) != hashSet.end()) {

            // Element is present, remove it
            // Adjust previous node's next pointer
            if (curr->prev)
                curr->prev->next = curr->next;

            // Adjust next node's prev pointer
            if (curr->next)
                curr->next->prev = curr->prev;

            // Delete the curr node
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {

            // Element is not present, add it to hash table
            hashSet.insert(curr->data);
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node *head) {
  	Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    // Create a doubly linked list:
  	// 1 <-> 2 <-> 3 <-> 2 <-> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    head = removeDuplicates(head);

    printList(head);

}
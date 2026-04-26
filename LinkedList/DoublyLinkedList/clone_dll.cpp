#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
using namespace std;

/*
138. Copy List with Random Pointer
https://leetcode.com/problems/copy-list-with-random-pointer/

https://www.geeksforgeeks.org/dsa/a-linked-list-with-next-and-arbit-pointer/
*/
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *curr = head;
        /*
                Step 1 :
                Insert copied nodes after each original node
                A->B->C
                becomes
                A->A'->B->B'->C->C'
        */
        while (curr)
        {
            Node *copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }
        /*
              Step 2:
              Assign random pointers for copied nodes
              copy.random = original.random.next
              */
        curr = head;
        while (curr)
        {
            if (curr->random)
                curr->next->random = curr->random->next;
            else
                curr->next->random = nullptr;

            curr = curr->next->next;
        }

        // step 3
        // Separate original and copied lists
        curr = head;
        Node *copyHead = head->next;
        while (curr)
        {
            Node *copy = curr->next;
            // restore original list
            curr->next = copy->next;

            // connect copy list
            if (copy->next)
                copy->next = copy->next->next;
            curr=curr->next;

        }
        return copyHead;

    }
};

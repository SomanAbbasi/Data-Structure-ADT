#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;



/*
https://leetcode.com/problems/rotate-list/
61. Rotate List

*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        //  Find length and tail
        ListNode *tail = head;
        int ln = 1;

        while (tail->next)
        {
            tail = tail->next;
            ln++;
        }

        k = k % ln;
        if (k == 0)
            return head;

        // make circular
        tail->next=head;

        //Find new tail
        int count=ln-k-1;
        ListNode *newTail=head;
        for (int i = 0; i < count; i++)
        {
            newTail=newTail->next;

        }

        //Break the Circle

        ListNode *newHead=newTail->next;
        newTail->next=nullptr;

        return newHead;
        

    }
};

int main()
{
}
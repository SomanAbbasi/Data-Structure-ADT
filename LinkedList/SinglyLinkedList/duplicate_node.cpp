#include<iostream>
#include<vector>
using namespace std;


/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (!head)
            return nullptr;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr)
        {

            // detect duplicate block
            if (curr->next && curr->val == curr->next->val)
            {

                int val = curr->val;

                // skip all nodes with this value
                while (curr && curr->val == val)
                {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else
            {
                // unique node
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
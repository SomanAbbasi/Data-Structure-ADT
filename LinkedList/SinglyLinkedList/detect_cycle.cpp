#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;

/*
https://leetcode.com/problems/linked-list-cycle-ii/description/
142. Linked List Cycle II
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: Find cycle start
                ListNode* entry = head;

                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        return nullptr; // No cycle
    }
};
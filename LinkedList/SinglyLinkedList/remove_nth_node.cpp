#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;


/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list

19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            len+=1;
            temp=temp->next;

        }
        if(n==len)
        {
            ListNode *temp=head;
            temp=head->next;
            delete head;
            return temp;

        }
        int count=1;
        temp=head;
        while(count<len-n)

        {
            temp=temp->next;
            count+=1;
        }

        ListNode * delNode=temp->next;
        temp->next=delNode->next;
        delete delNode;
        return head;

        
    }
};
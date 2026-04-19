#include<iostream>
#include<vector>
#include<string>
#include<forward_list>

using namespace std;



/*

https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
2807. Insert Greatest Common Divisors in Linked List

*/
  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 


class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(!head || !head->next) return head;

        ListNode *curr=head;
        while (curr && curr->next)
        {
            ListNode *nxtNode=curr->next;

            int g=gcd(curr->val,nxtNode->val);

            //Create a new Node
            ListNode *newNode=new ListNode(g);

            //Insert between curr && nextNode
            curr->next=newNode;
            newNode->next=nxtNode;

            curr=nxtNode;

        }

        return head;
        

    }
};

int main()
{
    forward_list<int> ll={18,6,10,3};
    


}
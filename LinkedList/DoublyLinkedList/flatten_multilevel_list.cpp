#include <iostream>
#include <vector>
#include <string>
#include <forward_list>

using namespace std;



/*

https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

430. Flatten a Multilevel Doubly Linked List
*/
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution
{
public:
    Node *dfs(Node* head)
    {
        Node *curr=head;
        Node *last=head;
        while (curr)
        {
            Node *nextNode=curr->next;

            //If current has a child then go for it
            if(curr->child)
            {
                Node *childHead=curr->child;

                // flat it and get tail
                Node *childTail=dfs(childHead);

                // insert child b/w curr and nextNode
                curr->next=childHead;
                childHead->prev=curr;

                curr->child=nullptr;

                //Connect child tail with original Curr
                if(nextNode)
                {
                    childTail->next=nextNode;
                    nextNode->prev=childTail;
                }
                last=childTail;
            }
            else{
                last=curr;
            }
            curr=nextNode;
        }
        return last;

        
    }

    Node *flatten(Node *head)
    {

        if (!head)
            return nullptr;

        dfs(head);

        return head;
    }
};


/*
         =====   ITERATIVE SOLUTION =====

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        stack<Node*> cont;

        while(curr || !cont.empty()){
            if(curr->child != nullptr){
                if (curr->next) cont.push(curr->next);   
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            }
            if(curr->next == nullptr && !cont.empty()){
                curr->next = cont.top();
                curr->next->prev = curr;
                cont.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};

*/

int main()
{
}
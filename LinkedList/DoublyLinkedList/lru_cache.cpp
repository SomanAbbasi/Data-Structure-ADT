#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
using namespace std;


/*

146. LRU Cache
https://leetcode.com/problems/lru-cache/description/?envType=problem-list-v2&envId=doubly-linked-list

*/

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;

        Node *prev;
        Node *next;
        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = next = nullptr;
        }
    };
    int cap;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;

    // remove node from list
    void removeNode(Node *node)
    {
        Node *before = node->prev;
        Node *after = node->next;

        before->next = after;
        after->prev = before;
    }

    // insert after head
    void insertFront(Node *node)
    {
        Node *firstRealNode = head->next;
        node->next = firstRealNode;
        node->prev = head;

        head->next = node;
        firstRealNode->prev = node;
    }

    // move existing node to front
    void moveToFront(Node *node)
    {
        removeNode(node);
        insertFront(node);
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;

        // DummyNode to Avoid edge
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        if(mp.find(key)==mp.end())
        {
            return -1;   
        }

        Node *node=mp[key];

        // accessed -> becomes most recently used
        moveToFront(node);

        return node->value;

    }

    void put(int key, int value)
    {
        // key already exits
        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];

            node->value=value;

            moveToFront(node);
            return;
        }

        //New node
        Node *newNode=new Node(key,value);
        mp[key]=newNode;

        insertFront(newNode);

        if(mp.size()>cap)
        {

            Node *lru=tail->prev;
            removeNode(lru);

            mp.erase(lru->key);

            delete lru;

        }

    }
};

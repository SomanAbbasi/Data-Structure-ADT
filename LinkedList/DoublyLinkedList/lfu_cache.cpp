#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
using namespace std;



/*
460. LFU Cache


https://leetcode.com/problems/lfu-cache/


*/
class LFUCache
{
private:
    // Node for cache entry just like lru
    struct Node
    {
        int key;
        int value;
        int freq;

        Node *prev;
        Node *next;
        Node(int k, int v)
        {
            key = k;
            value = v;
            freq = 1;
            prev = next = nullptr;
        }
    };

    // list for same freq
    struct DLL
    {
        Node *head;
        Node *tail;

        int size;

        DLL()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        // Insert as most recently used
        void insertFront(Node *node)
        {

            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        void removeNode(Node *node)
        {

            Node *before = node->prev;
            Node *after = node->next;

            before->next = after;
            after->prev = before;

            size--;
        }
        // remove least recently used in this freq
        Node *removeLRU()
        {

            if (size == 0)
                return nullptr;

            Node *node = tail->prev;

            removeNode(node);

            return node;
        }
    };
    int cap;
    int currSize;
    int minFreq;

    unordered_map<int, Node *> keyMp;
    unordered_map<int, DLL *> freqMp;

    // increase freq of node

    void updateFreq(Node *node)
    {
        int oldFreq = node->freq;

        freqMp[oldFreq]->removeNode(node);
        // if old minimum freq became empty
        if (oldFreq == minFreq &&
            freqMp[oldFreq]->size == 0)
        {
            minFreq++;
        }
        node->freq++;

        if (freqMp.find(node->freq) == freqMp.end())
        {
            freqMp[node->freq] = new DLL();
        }

        freqMp[node->freq]->insertFront(node);
    }

public:
    LFUCache(int capacity)
    {
        cap = capacity;
        currSize = 0;
        minFreq = 0;
    }
    int get(int key)
    {
        if (keyMp.find(key) == keyMp.end())
        {
            return -1;
        }

        Node *node = keyMp[key];
        updateFreq(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;

        if (keyMp.find(key) != keyMp.end())
        {
            Node *node = keyMp[key];
            node->value = value;

            updateFreq(node);
            return;
        }

        // Cache full evict lfu cache

        if (currSize == cap)
        {
            Node *lfuNode = freqMp[minFreq]->removeLRU();

            keyMp.erase(lfuNode->key);
            delete lfuNode;

            currSize--;
        }

        // insert new node
        Node *newNode = new Node(key, value);
        minFreq = 1;
        if (freqMp.find(1) == freqMp.end())
        {
            freqMp[1] = new DLL();
        }

        freqMp[1]->insertFront(newNode);

        keyMp[key] = newNode;
        currSize++;

    }
};

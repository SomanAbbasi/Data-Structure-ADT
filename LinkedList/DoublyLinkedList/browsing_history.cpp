#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <unordered_map>
using namespace std;

/*

1472. Design Browser History

https://leetcode.com/problems/design-browser-history/description/?envType=problem-list-v2&envId=doubly-linked-list
*/

/*
Operations:

visit(url)
=> Open a new webpage from the current page.
back(steps)
=> Move backward in browsing history up to steps.
forward(steps)
=> Move forward in browsing history up to steps.

Important rule:

If you visit a new page after going back, all forward history is deleted.

Example:

leetcode -> google -> facebook -> youtube

If we go back twice:

Current = google

Forward history exists:

facebook -> youtube

Now if we visit:

linkedin

History becomes:

leetcode -> google -> linkedin

And:

facebook, youtube  (deleted)
*/
class BrowserHistory
{
private:
    struct Node
    {
        string url;
        Node *prev;
        Node *next;
        Node(string s)
        {
            url = s;
            prev = nullptr;
            next = nullptr;
        }
    };
    Node *current;

public:
    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string url)
    {
        // clear forward history
        if (current->next)
        {
            Node *temp = current->next;

            while (temp)
            {
                Node *nxt = temp->next;
                delete temp;
                temp = nxt;
            }
            current->next = nullptr;
            // add new page

            Node *newPage = new Node(url);

            current->next = newPage;
            newPage->prev = current;
            current = newPage;
        }
    }

    string back(int steps)
    {
        while (steps-- && current->prev)
        {
            current = current->prev;
        }

        return current->url;
    }

    string forward(int steps)
    {
        while (steps-- && current->next)
        {
            current = current->next;
        }

        return current->url;
    }
};

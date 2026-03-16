#include <deque>
using namespace std;



/*

Concept

Insertion and deletion from both ends.

Operations:

pushFront()
pushBack()
popFront()
popBack()

Example:

Front ← 10 20 30 → Rear

*/
class DequeADT {

private:
    deque<int> dq;

public:

    void pushFront(int x) {
        dq.push_front(x);
    }

    void pushBack(int x) {
        dq.push_back(x);
    }

    void popFront() {

        if (!dq.empty())
            dq.pop_front();
    }

    void popBack() {

        if (!dq.empty())
            dq.pop_back();
    }

    int getFront() {

        if (dq.empty())
            return -1;

        return dq.front();
    }

    int getBack() {

        if (dq.empty())
            return -1;

        return dq.back();
    }

    bool isEmpty() {
        return dq.empty();
    }
};
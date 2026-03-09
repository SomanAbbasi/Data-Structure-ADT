#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
779. K-th Symbol in Grammar
https://leetcode.com/problems/k-th-symbol-in-grammar/

*/

/*
Each row has:

length = 2^(n-1)

And each row is built from the previous row:

previous row = A
new row = A + invert(A)



Recursive Insight

    For row n:

    mid = 2^(n-2)

    Two cases:

    Case 1 — First Half

    If:

    k <= mid

    Then symbol is exactly the same as previous row.

    kth(n,k) = kth(n-1,k)

    Case 2 — Second Half

    If:

    k > mid

    Then it belongs to the inverted second half.

    Position in previous row:

    k' = k - mid

    Then flip the result.

    kth(n,k) = !kth(n-1,k-mid)

*/



int kthGrammar(int n,int k)
{
    if(n==1)
        return 0;

    int mid = 1 << (n-2);  // 2^(n-2)

    if(k<=mid)
    {
        return kthGrammar(n-1,k);
    }
    else{
        return !kthGrammar(n-1,k-mid);

    }

    
}


int main()
{

    int n = 4;
    int k = 5;

    cout << kthGrammar(n,k);

}
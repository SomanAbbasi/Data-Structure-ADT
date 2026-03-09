
#include <iostream>
#include<vector>
using namespace std;



/*


https://www.geeksforgeeks.org/dsa/josephus-problem/
*/

//Method 1:

/* Iterative Version */
/*
#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    int res = 0;

    for(int i = 2; i <= n; i++)
        res = (res + k) % i;

    return res + 1;
}

int main()
{
    int n = 7, k = 3;

    cout << josephus(n, k);
}
*/


//Method 2:
/* Using Recursive Relation - O(n) Time and O(n) Space*/


/*
#include <iostream>
using namespace std;

int josephus(int n, int k)
{
    // Base case
    if (n == 1)
        return 0;

    // Recursive relation
    return (josephus(n - 1, k) + k) % n;
}

int main()
{
    int n = 7;
    int k = 3;

    cout << "Survivor position: " << josephus(n, k) + 1 << endl;

    return 0;
}

*/



//Method 3:
int josephusRec(vector<int> person,int k , int index)
{
    if(person.size()==1) 
        return person[0];
    
    index=(index+k)%person.size();

    person.erase(person.begin()+index);

    return josephusRec(person,k,index);


}



int josephus(int n,int k)
{
    int idx=0;
    vector<int> person;
    for (int i = 0; i < n; i++)
    {
        person.push_back(i);
    }

    return josephusRec(person,k,idx);

    
}

int main()
{
    int n=5; //n -> people
    int k=2; // kth person elminated

    //(k-1 ) person will be killed

}
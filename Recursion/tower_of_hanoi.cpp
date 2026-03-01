#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
/*
Tower of Hanoi
https://www.geeksforgeeks.org/dsa/c-program-for-tower-of-hanoi/


Method:
    => Shift 'n-1' disks from 'A' to 'B', using C.
    => Shift last disk from 'A' to 'C'.
    => Shift 'n-1' disks from 'B' to 'C', using A.



Time Complexity:
    O(2^n) => There are two possibilities for every disk. Therefore, 2 * 2 * 2 * . . . * 2(n times) is 2^n

Auxiliary Space: 
    O(n) =>  Function call stack space

*/


void towerOfHanoi(int n,char fromRod,char toRod, char auxRod)
{
    if(n==0) return;

    towerOfHanoi(n-1,fromRod,auxRod,toRod);
    cout<<"Disk "<<n<< " moved from "<<fromRod<<" to "<<toRod<<endl;
    towerOfHanoi(n-1,auxRod,toRod,fromRod);
}


int main()
{
    int n=3;

    towerOfHanoi(n,'A','C','B');

}
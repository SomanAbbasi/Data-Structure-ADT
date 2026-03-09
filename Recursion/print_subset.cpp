#include <iostream>
#include <vector>
using namespace std;


/*
78. Subsets
https://leetcode.com/problems/subsets/description/

*/

void printSubset(vector<int>& arr, vector<int>& current, int index)
{
    // base case
    if(index == arr.size())
    {
        cout << "{ ";
        for(int x : current)
            cout << x << " ";
        cout << "}" << endl;
        return;
    }

    // exclude element
    printSubset(arr, current, index+1);

    // include element
    current.push_back(arr[index]);
    printSubset(arr, current, index+1);

    // backtrack
    current.pop_back();
}

int main()
{
    vector<int> arr = {1,2,3};
    vector<int> current;

    printSubset(arr, current, 0);
}
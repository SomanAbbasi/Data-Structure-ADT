#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

int solve(int arr[], int n, int choice, int result, int idx)
{
    if (choice == 2)
    {
        return result;
    }
    if (idx >= n)
        return INT_MIN;


    int take = solve(arr, n, choice + 1, result * arr[idx], idx + 1);
    int notake = solve(arr, n, choice , result, idx + 1);
    return max(take,notake);

}

int maxProductRecursive(int arr[], int n)
{

    int res = solve(arr, n, 0, 1, 0);
    return res;
}

int main()
{

    int arr[4] = {1, 3, 5, 2};
    int n = 4;
    int res = maxProductRecursive(arr, n);
    cout << "Maximum= " << res << endl;
}
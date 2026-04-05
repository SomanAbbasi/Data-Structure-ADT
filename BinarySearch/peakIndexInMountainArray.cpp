#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

/*
https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
*/
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int prev = (mid == 0) ? INT_MIN : arr[mid - 1];
            int next =( mid == n-1) ? INT_MIN : arr[mid +1 ];
            if(prev<arr[mid]&& arr[mid]>next)
            {
                return mid;
            }
            else if(arr[mid]<prev)
            {
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
    return -1;
    }
};

int main()
{
}
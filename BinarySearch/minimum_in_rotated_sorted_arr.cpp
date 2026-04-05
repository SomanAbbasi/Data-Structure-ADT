#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    Solution s1;
    cout << s1.findMin(arr) << endl;
}
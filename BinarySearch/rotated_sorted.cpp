#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*

https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;

            if ((nums[left] <= nums[mid]))
            {
                if (nums[left] <=target && nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && nums[right] >= target)
                {
                    left=mid+1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    Solution s1;
    cout << s1.search(arr, 0) << endl;
}
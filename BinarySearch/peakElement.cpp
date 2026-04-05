#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

/*

https://leetcode.com/problems/find-peak-element/

*/
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main()
{
}
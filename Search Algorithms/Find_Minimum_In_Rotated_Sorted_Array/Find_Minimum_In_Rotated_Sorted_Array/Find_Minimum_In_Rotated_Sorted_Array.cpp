// LeetCode #153: Find Minimum in Rotated Sorted Array
// Problem link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Time complexity: O(log n)
// Space complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{
    vector<int> nums = { 4,5,6,7,0,1,2 };
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}
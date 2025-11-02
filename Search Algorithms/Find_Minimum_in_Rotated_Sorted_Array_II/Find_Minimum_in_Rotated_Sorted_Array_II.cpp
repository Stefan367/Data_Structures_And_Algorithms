// LeetCode #154: Find Minimum in Rotated Sorted Array II
// Approach: Binary Search with duplicate handling
// Time complexity: O(log n) on average, O(n) in the worst case (when duplicates)
// Space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else if (nums[mid] == nums[right])
            {
                right--;
            }
            else
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = { 3, 4, 5, 1, 2 };
    vector<int> nums2 = { 2, 2, 2, 0, 1 };
    vector<int> nums3 = { 1, 3, 5 };

    cout << sol.findMin(nums1) << endl; // Output: 1
    cout << sol.findMin(nums2) << endl; // Output: 0
    cout << sol.findMin(nums3) << endl; // Output: 1
}

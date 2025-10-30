// LeetCode #540: Single Element in a Sorted Array
// Approach: Binary Search (pair index parity)
// Time complexity: O(log n)
// Space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;

		while (left < right)
		{
			int mid = left + (right - left) / 2;

			if (mid % 2 == 0)
			{
				if (nums[mid] != nums[mid + 1])
				{
					right = mid;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if (nums[mid] != nums[mid + 1])
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
		}
		return nums[left];
	}
};

int main() {
    Solution sol;
    vector<int> nums1 = { 1,1,2,3,3,4,4,8,8 };
    vector<int> nums2 = { 3,3,7,7,10,11,11 };

    cout << sol.singleNonDuplicate(nums1) << endl; // Output: 2
    cout << sol.singleNonDuplicate(nums2) << endl; // Output: 10
}

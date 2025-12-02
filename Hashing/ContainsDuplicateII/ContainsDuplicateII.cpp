// LeetCode problem: 219. Contains Duplicate II
// Difficulty: Easy
// Link: https://leetcode.com/problems/contains-duplicate-ii/
// Description: Check if an array contains duplicates within a distance k using a hash map.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		// nums_map <number, index>
		unordered_map<int, int> nums_map;

		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = nums_map.find(nums[i]);

			if (iter != nums_map.end())
			{
				if (abs(iter->second - i) <= k)
				{
					return true;
				}
			}
			nums_map[nums[i]] = i;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = { 1, 2, 3, 1 };
	cout << boolalpha << sol.containsNearbyDuplicate(nums, 3) << endl; // true
	return 0;
}

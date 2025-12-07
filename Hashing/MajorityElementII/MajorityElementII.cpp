// LeetCode problem: 229. Majority Element II
// Difficulty: Medium
// Link: https://leetcode.com/problems/majority-element-ii/
// Description: Find all elements that appear more than n/3 times in the array.
//              Uses a hash map to count occurrences and then extracts valid majority elements.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> num_count;
		vector<int> majorityEls;
		int n = nums.size();

		for (int i = 0; i < n; i++)
		{
			num_count[nums[i]]++;
		}

		for (auto& [num, count] : num_count)
		{
			if (count > n / 3)
			{
				majorityEls.push_back(num);
			}
		}

		return majorityEls;
	}
};

int main()
{
	Solution sol;

	vector<int> t1 = { 3, 2, 3 };
	auto r1 = sol.majorityElement(t1);
	cout << "Test 1 (expected [3]): ";
	for (int x : r1) cout << x << " ";
	cout << endl;

	vector<int> t2 = { 1 };
	auto r2 = sol.majorityElement(t2);
	cout << "Test 2 (expected [1]): ";
	for (int x : r2) cout << x << " ";
	cout << endl;

	vector<int> t3 = { 1, 2 };
	auto r3 = sol.majorityElement(t3);
	cout << "Test 3 (expected [1,2] or either depending on n/3 rule): ";
	for (int x : r3) cout << x << " ";
	cout << endl;

	vector<int> t4 = { 1,1,1,3,3,2,2,2 };
	auto r4 = sol.majorityElement(t4);
	cout << "Test 4 (expected [1,2]): ";
	for (int x : r4) cout << x << " ";
	cout << endl;

	return 0;
}

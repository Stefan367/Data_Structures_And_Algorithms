/**
 * LeetCode 2762: Continuous Subarrays
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/continuous-subarrays/
 *
 * We count subarrays where (max - min) <= 2.
 * Sliding window + ordered map (frequency) lets us maintain current min/max in O(log n) updates.
 */

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	long long continuousSubarrays(vector<int>& nums) {
		long long count = 0;

		map<int, int> freq;

		int l = 0, r = 0;

		while (r < (int)nums.size())
		{
			freq[nums[r]]++;

			while (freq.rbegin()->first - freq.begin()->first > 2)
			{
				freq[nums[l]]--;

				if (freq[nums[l]] == 0)
				{
					freq.erase(nums[l]);
				}
				l++;
			}
			count += (r - l + 1);
			r++;
		}

		return count;
	}
};

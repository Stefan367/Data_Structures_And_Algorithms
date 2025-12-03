// LeetCode problem: 2364. Count Number of Bad Pairs
// Difficulty: Medium
// Link: https://leetcode.com/problems/count-number-of-bad-pairs/
// Description: Count the number of bad pairs (i, j) such that i < j and j - i != nums[j] - nums[i].
//              Uses the observation that good pairs satisfy nums[j] - j == nums[i] - i.
//              We count good pairs in O(n) with a hash map, then subtract from total pairs.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodPairs = 0;
        unordered_map<long long, long long> good_count;
        long long numsLen = nums.size();
        long long totalPairs = numsLen * (numsLen - 1) / 2;

        for (int i = 0; i < numsLen; i++)
        {
            long long key = static_cast<long long>(nums[i]) - i;

            goodPairs += good_count[key];

            good_count[key]++;
        }
        return totalPairs - goodPairs;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = { 4, 1, 3, 3 };
    cout << sol.countBadPairs(t1) << " (expected 5)" << endl;

    vector<int> t2 = { 1, 2, 3, 4, 5 };
    cout << sol.countBadPairs(t2) << " (expected 10)" << endl;

    vector<int> t3 = { 1, 1, 1, 1 };
    cout << sol.countBadPairs(t3) << " (expected 6)" << endl;

    return 0;
}
// LeetCode problem: 560. Subarray Sum Equals K
// Difficulty: Medium
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Description: Count the number of continuous subarrays whose sum equals k.
//              Uses prefix sums + hash map to achieve O(n) complexity.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> sum_count;
        int sum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum == k)
                count++;

            if (sum_count.find(sum - k) != sum_count.end())
                count += sum_count[sum - k];

            sum_count[sum]++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = { 1, 1, 1 };
    cout << sol.subarraySum(t1, 2) << " (expected 2)" << endl;

    vector<int> t2 = { 1, 2, 3 };
    cout << sol.subarraySum(t2, 3) << " (expected 2)" << endl;

    vector<int> t3 = { 1 };
    cout << sol.subarraySum(t3, 0) << " (expected 0)" << endl;

    vector<int> t4 = { 3, 4, 7, 2, -3, 1, 4, 2 };
    cout << sol.subarraySum(t4, 7) << " (expected 4)" << endl;

    return 0;
}

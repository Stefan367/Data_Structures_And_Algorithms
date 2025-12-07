// LeetCode problem: 268. Missing Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/missing-number/
// Description: Given an array containing n distinct numbers taken from 0 to n,
//              find the one that is missing. This solution uses a hash set
//              (unordered_set) to store all present numbers and then scans
//              from 0 to n to find the missing one.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> numbers;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            numbers.insert(nums[i]);
        }

        for (int i = 0; i <= n; ++i)
        {
            if (numbers.find(i) == numbers.end())
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = { 3, 0, 1 };
    cout << "Test 1 (expected 2): " << sol.missingNumber(t1) << '\n';

    vector<int> t2 = { 0, 1 };
    cout << "Test 2 (expected 2): " << sol.missingNumber(t2) << '\n';

    vector<int> t3 = { 1, 2 };
    cout << "Test 3 (expected 0): " << sol.missingNumber(t3) << '\n';

    vector<int> t4 = { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
    cout << "Test 4 (expected 8): " << sol.missingNumber(t4) << '\n';

    return 0;
}

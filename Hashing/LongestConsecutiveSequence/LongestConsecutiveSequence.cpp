// LeetCode problem: 128. Longest Consecutive Sequence
// Difficulty: Medium
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Description: Find the length of the longest sequence of consecutive integers using an unordered_set for O(1) lookup.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> setNums;

        for (int& num : nums)
            setNums.insert(num);

        int maxCount = 0;
        for (auto x : setNums)
        {
            if (!setNums.count(x - 1))
            {
                int counter = 0;
                int current = x;
                while (true)
                {
                    if (!setNums.count(current))
                        break;

                    current++;
                    counter++;
                }
                if (counter > maxCount)
                {
                    maxCount = counter;
                }
            }
        }
        return maxCount;
    }
};

int main()
{
    Solution sol;

    vector<int> test1 = { 100, 4, 200, 1, 3, 2 };
    cout << "Test 1 (expected 4): " << sol.longestConsecutive(test1) << endl;

    vector<int> test2 = { 0,3,7,2,5,8,4,6,0,1 };
    cout << "Test 2 (expected 9): " << sol.longestConsecutive(test2) << endl;

    vector<int> test3 = {};
    cout << "Test 3 (expected 0): " << sol.longestConsecutive(test3) << endl;

    vector<int> test4 = { 1 };
    cout << "Test 4 (expected 1): " << sol.longestConsecutive(test4) << endl;

    return 0;
}

// LeetCode problem: 55. Jump Game
// Difficulty: Medium
// Link: https://leetcode.com/problems/jump-game/
// Description: Given an array nums where nums[i] is the maximum jump length from index i,
//              determine if you can reach the last index starting from index 0.
//              This solution uses a DP-style reachability array: dp[i] = can we reach index i.
// Time complexity: O(n^2) in the worst case
// Space complexity: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 0; i < n; i++)
        {
            if (!dp[i])
                return false;

            int furthestJump = min(i + nums[i], n - 1);

            for (int j = furthestJump; j >= i; j--)
            {
                if (dp[j])
                    break;

                dp[j] = true;
            }
        }

        return dp[n - 1];
    }
};

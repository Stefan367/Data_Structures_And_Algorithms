// LeetCode problem: 70. Climbing Stairs
// Difficulty: Easy
// Link: https://leetcode.com/problems/climbing-stairs/
// Description: Given n stairs, you can climb 1 or 2 steps at a time.
//              Count how many distinct ways you can reach the top.
//              Uses bottom-up dynamic programming (tabulation).
// Time complexity: O(n)
// Space complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) 
            return 1;

        if (n == 2) 
            return 2;

        vector<int> dp(n + 1, -1);
        dp[1] = 1, dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

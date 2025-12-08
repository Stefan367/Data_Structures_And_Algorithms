// LeetCode problem: 746. Min Cost Climbing Stairs
// Difficulty: Easy
// Link: https://leetcode.com/problems/min-cost-climbing-stairs/
// Description: Given an array cost, where cost[i] is the cost of step i,
//              you can start at step 0 or 1 and climb 1 or 2 steps at a time.
//              Find the minimum cost to reach the top of the floor
//              using bottom-up dynamic programming.
// Time complexity: O(n)
// Space complexity: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 1)
            return cost[0];

        if (n == 2)
            return min(cost[0], cost[1]);

        vector<int> dp(n, 0);
        dp[0] = cost[0], dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(dp[n - 1], dp[n - 2]);
    }
};

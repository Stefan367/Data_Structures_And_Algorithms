// LeetCode problem: 322. Coin Change
// Difficulty: Medium
// Link: https://leetcode.com/problems/coin-change/
// Description: Given coin denominations and a target amount, find the minimum number
//              of coins needed to make up that amount. If it's not possible, return -1.
//              Uses bottom-up dynamic programming where dp[i] represents the minimum
//              number of coins needed to form amount i.
// Time complexity: O(amount * number_of_coins)
// Space complexity: O(amount)

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int& coin : coins)
            {
                if (i >= coin && dp[i - coin] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

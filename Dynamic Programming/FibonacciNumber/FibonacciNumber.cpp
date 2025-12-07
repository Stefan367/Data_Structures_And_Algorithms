// LeetCode problem: 509. Fibonacci Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/fibonacci-number/
// Description: Compute the nth Fibonacci number using top-down dynamic programming (memoization).
//              Stores intermediate results in a DP array to avoid redundant recursion.
// Time complexity: O(n)
// Space complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    int fibHelper(int n, vector<int>& dp)
    {
        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        if (dp[n] == -1)
        {
            dp[n] = fibHelper(n - 1, dp) + fibHelper(n - 2, dp);
        }
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);

        return fibHelper(n, dp);
    }
};

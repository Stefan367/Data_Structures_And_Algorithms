// LeetCode problem: 64. Minimum Path Sum
// Difficulty: Medium
// Link: https://leetcode.com/problems/minimum-path-sum/
// Description: Given a grid of non-negative numbers, find a path from top-left
//              to bottom-right which minimizes the sum of all numbers along its path.
//              You can only move either down or right at any point in time.
//              Uses bottom-up DP: dp[i][j] is the minimal path sum to cell (i, j).
// Time complexity: O(rows * cols)
// Space complexity: O(rows * cols)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (rows == 1 && cols == 1)
            return grid[0][0];

        vector<vector<int>> dp(rows, vector<int>(cols));
        dp[0][0] = grid[0][0];

        for (int j = 1; j < cols; j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < rows; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

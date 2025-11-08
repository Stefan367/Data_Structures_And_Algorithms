// LeetCode problem: 643. Maximum Average Subarray I
// Link: https://leetcode.com/problems/maximum-average-subarray-i/
// Description: Solution using a sliding window implemented with a queue.
// Time complexity: O(n)
// Space complexity: O(k)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        queue<int> window;
        int currSum = 0, maxSum = 0;

        for (int i = 0; i < k; ++i)
        {
            window.push(nums[i]);
            currSum += nums[i];
        }

        int numsSize = nums.size();
        maxSum = currSum;
        for (int i = k; i < numsSize; ++i)
        {
            currSum += nums[i] - window.front();
            window.push(nums[i]);
            window.pop();

            if (maxSum < currSum)
                maxSum = currSum;
        }

        return (maxSum * 1.0) / k;
    }
};

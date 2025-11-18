// LeetCode problem: 239. Sliding Window Maximum
// Link: https://leetcode.com/problems/sliding-window-maximum/
// Description: Sliding window maximum solved using a monotonic deque.
// NOTE: This version stores values instead of indices.
// Time complexity: O(n)
// Space complexity: O(k)

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        deque<int> deq;

        for (int i = 0; i < k; i++) {
            while (!deq.empty() && deq.back() < nums[i])
                deq.pop_back();

            deq.push_back(nums[i]);
        }

        result.push_back(deq.front());

        for (int i = k; i < nums.size(); i++) {
            if (deq.front() == nums[i - k])
                deq.pop_front();

            while (!deq.empty() && deq.back() < nums[i])
                deq.pop_back();

            deq.push_back(nums[i]);
            result.push_back(deq.front());
        }

        return result;
    }
};

// LeetCode problem: 215. Kth Largest Element in an Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Description: Keep a min-heap of size k; after processing all elements, the heap top is the k-th largest.
// Time complexity: O(n log k)
// Space complexity: O(k)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();

        priority_queue<int, vector<int>, greater<int>>
            pq(nums.begin(), nums.begin() + k);

        for (int i = k; i < size; i++)
        {
            pq.push(nums[i]);
            pq.pop();
        }

        return pq.top();
    }
};

int main()
{
    Solution sol;

    vector<int> a1 = { 3, 2, 1, 5, 6, 4 };
    cout << sol.findKthLargest(a1, 2) << " (expected 5)" << endl;

    vector<int> a2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    cout << sol.findKthLargest(a2, 4) << " (expected 4)" << endl;

    vector<int> a3 = { 1 };
    cout << sol.findKthLargest(a3, 1) << " (expected 1)" << endl;

    return 0;
}

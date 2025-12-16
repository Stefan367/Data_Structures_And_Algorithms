// LeetCode problem: 2530. Maximal Score After Applying K Operations
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximal-score-after-applying-k-operations/
// Description: Repeatedly take the largest element, add it to the score, replace it with ceil(x/3), and repeat k times.
// Time complexity: O((n + k) log n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long result = 0;
        priority_queue<int> pq(nums.begin(), nums.end());

        for (int i = 0; i < k; i++)
        {
            int currNum = pq.top();
            pq.pop();

            result += currNum;

            currNum = ceil(currNum / 3.0);
            pq.push(currNum);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> t1 = { 10, 10, 10 };
    cout << sol.maxKelements(t1, 3) << " (expected 30)" << endl;

    vector<int> t2 = { 1, 10, 3, 3, 3 };
    cout << sol.maxKelements(t2, 3) << " (expected 17)" << endl;

    vector<int> t3 = { 5 };
    cout << sol.maxKelements(t3, 5) << " (expected 9)" << endl;

    return 0;
}

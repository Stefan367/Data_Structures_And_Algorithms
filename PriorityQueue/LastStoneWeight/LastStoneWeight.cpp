// LeetCode problem: 1046. Last Stone Weight
// Difficulty: Easy
// Link: https://leetcode.com/problems/last-stone-weight/
// Description: Repeatedly smash the two heaviest stones; if they differ, push back the difference.
// Time complexity: O(n log n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x, y;
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1)
        {
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();

            if (y != x)
            {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main()
{
    Solution sol;

    vector<int> s1 = { 2, 7, 4, 1, 8, 1 };
    cout << sol.lastStoneWeight(s1) << " (expected 1)" << endl;

    vector<int> s2 = { 1 };
    cout << sol.lastStoneWeight(s2) << " (expected 1)" << endl;

    vector<int> s3 = { 3, 3 };
    cout << sol.lastStoneWeight(s3) << " (expected 0)" << endl;

    vector<int> s4 = { 10, 4, 2, 10 };
    cout << sol.lastStoneWeight(s4) << " (expected 2)" << endl;

    return 0;
}

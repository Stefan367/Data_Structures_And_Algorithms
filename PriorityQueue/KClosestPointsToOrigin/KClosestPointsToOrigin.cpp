// LeetCode problem: 973. K Closest Points to Origin
// Difficulty: Medium
// Link: https://leetcode.com/problems/k-closest-points-to-origin/
// Description: Return k points closest to (0,0) using a priority_queue with custom comparator.
// Time complexity: O(n + k log n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comparator
{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs) const
    {
        return lhs[0] * lhs[0] + lhs[1] * lhs[1] > rhs[0] * rhs[0] + rhs[1] * rhs[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq(points.begin(), points.end());

        vector<vector<int>> result;
        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> p1 = { {1,3},{-2,2} };
    auto r1 = sol.kClosest(p1, 1);
    cout << "[" << r1[0][0] << "," << r1[0][1] << "] (expected [-2,2])" << endl;

    vector<vector<int>> p2 = { {3,3},{5,-1},{-2,4} };
    auto r2 = sol.kClosest(p2, 2);
    cout << "[" << r2[0][0] << "," << r2[0][1] << "] and [" << r2[1][0] << "," << r2[1][1] << "] (expected two closest)" << endl;

    return 0;
}

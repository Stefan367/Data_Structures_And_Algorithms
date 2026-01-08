// LeetCode problem: 1631. Path With Minimum Effort
// Difficulty: Medium
// Link: https://leetcode.com/problems/path-with-minimum-effort/
// Description: Find a path from (0,0) to (n-1,m-1) minimizing the maximum absolute height difference between adjacent cells.
// Idea: Dijkstra on a grid where distance to a cell is the minimal possible "effort" (minimize the maximum edge on the path).
// Time complexity: O((n*m) log (n*m))
// Space complexity: O(n*m)

#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
public:
	struct Node
	{
		int r, c, weight;

		bool operator<(const Node& other) const
		{
			return weight > other.weight;
		}
	};

	int minimumEffortPath(vector<vector<int>>& heights) {
		int n = heights.size();
		int m = heights[0].size();

		vector<vector<int>> dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
		dist[0][0] = 0;

		priority_queue<Node> pq;
		pq.push({ 0, 0, 0 });

		while (!pq.empty())
		{
			auto current = pq.top();
			int row = current.r;
			int column = current.c;
			int weight = current.weight;
			pq.pop();

			if (weight > dist[row][column])
				continue;

			int step = 0, newEff = 0;
			int nc = 0, nr = 0;
			for (int i = 0; i < 4; i++)
			{
				if (i == 0)
				{
					nr = row - 1;
					nc = column;
				}
				else if (i == 1)
				{
					nr = row + 1;
					nc = column;
				}
				else if (i == 2)
				{
					nc = column - 1;
					nr = row;
				}
				else if (i == 3)
				{
					nc = column + 1;
					nr = row;
				}

				if (nr < 0 || nc < 0 || nr >= n || nc >= m)
					continue;

				step = abs(heights[row][column] - heights[nr][nc]);
				newEff = max(weight, step);

				if (newEff < dist[nr][nc])
				{
					dist[nr][nc] = newEff;
					pq.push({ nr, nc, newEff });
				}
			}
		}
		return dist[n - 1][m - 1];
	}
};

// LeetCode problem: 2290. Minimum Obstacle Removal to Reach Corner
// Difficulty: Hard
// Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
// Description: Move from (0,0) to (n-1,m-1) with minimum number of obstacles removed (grid cell value 1 adds cost).
// Idea: Dijkstra on a grid where edge cost is grid[nr][nc] (0 or 1). The distance is the minimum removals so far.
// Time complexity: O((n*m) log (n*m))
// Space complexity: O(n*m)

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
	struct Node
	{
		int r, c, weight;

		Node(int r, int c, int weight)
			: r(r), c(c), weight(weight) {
		}

		bool operator<(const Node& other) const
		{
			return weight > other.weight;
		}
	};

	int minimumObstacles(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
		distances[0][0] = 0;

		vector<vector<bool>> visited(n, vector<bool>(m, false));

		priority_queue<Node> pq;
		pq.push({ 0, 0, 0 });

		while (!pq.empty())
		{
			auto current = pq.top();
			int row = current.r;
			int col = current.c;
			int weight = current.weight;
			pq.pop();

			int step = 0;
			int nr = 0, nc = 0;
			if (!visited[row][col])
			{
				visited[row][col] = true;

				for (int i = 0; i < 4; i++)
				{
					switch (i)
					{
					case 0:
						nr = row - 1;
						nc = col;
						break;

					case 1:
						nr = row + 1;
						nc = col;
						break;

					case 2:
						nc = col - 1;
						nr = row;
						break;

					case 3:
						nc = col + 1;
						nr = row;
						break;
					}

					if (nr < 0 || nc < 0 || nr > n - 1 || nc > m - 1)
						continue;

					if (visited[nr][nc])
						continue;

					step = weight + grid[nr][nc];

					if (step < distances[nr][nc])
					{
						distances[nr][nc] = step;
						pq.push({ nr, nc, step });
					}
				}
			}
		}
		return distances[n - 1][m - 1];
	}
};

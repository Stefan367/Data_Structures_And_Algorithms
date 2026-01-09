// LeetCode problem: 1368. Minimum Cost to Make at Least One Valid Path in a Grid
// Difficulty: Hard
// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// Description: Each cell points in a direction (1=right, 2=left, 3=down, 4=up). Moving in the indicated direction costs 0,
//              otherwise costs 1 (change the arrow). Find the minimum cost to reach (n-1, m-1) from (0,0).
// Idea: Build a graph with n*m nodes. From each cell, add a 0-cost edge in the arrow direction (if valid),
//       and 1-cost edges to the other valid neighbors. Run Dijkstra from node 0.
// Time complexity: O((n*m) log (n*m))
// Space complexity: O(n*m)

#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
	struct Edge
	{
		int to, weight;
	};

	struct Node
	{
		int index, distance;

		bool operator<(const Node& other) const
		{
			return distance > other.distance;
		}
	};

	bool check(const int row, const int col, const int n, const int m)
	{
		return row >= 0 && col >= 0 && row < n && col < m;
	}

	int dijkstra(const vector<vector<Edge>>& graph, int n, int start)
	{
		vector<int> distances(n, INT_MAX);
		distances[start] = 0;

		priority_queue<Node> pq;
		pq.push({ start, 0 });

		while (!pq.empty())
		{
			auto current = pq.top();
			pq.pop();

			if (current.distance > distances[current.index])
				continue;

			for (const auto& edge : graph[current.index])
			{
				int newWeight = current.distance + edge.weight;
				if (newWeight < distances[edge.to])
				{
					distances[edge.to] = newWeight;
					pq.push({ edge.to, newWeight });
				}
			}
		}
		return distances[n - 1];
	}

	int minCost(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<Edge>> graph(n * m);

		int nr = -1, nc = -1;
		int index = 0;
		int neighborIndex = -1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int madedEdge = -1;
				switch (grid[i][j])
				{
				case 1:
					if (check(i, j + 1, n, m))
					{
						graph[index].push_back({ index + 1, 0 });
						madedEdge = 1;
					}
					break;

				case 2:
					if (check(i, j - 1, n, m))
					{
						graph[index].push_back({ index - 1, 0 });
						madedEdge = 2;
					}
					break;

				case 3:
					if (check(i + 1, j, n, m))
					{
						graph[index].push_back({ index + m, 0 });
						madedEdge = 3;
					}
					break;

				case 4:
					if (check(i - 1, j, n, m))
					{
						graph[index].push_back({ index - m, 0 });
						madedEdge = 4;
					}
					break;
				}

				for (int k = 1; k <= 4; k++)
				{
					if (madedEdge == k) continue;

					switch (k)
					{
					case 1:
						nr = i;
						nc = j + 1;
						neighborIndex = index + 1;
						break;

					case 2:
						nr = i;
						nc = j - 1;
						neighborIndex = index - 1;
						break;

					case 3:
						nr = i + 1;
						nc = j;
						neighborIndex = index + m;
						break;

					case 4:
						nr = i - 1;
						nc = j;
						neighborIndex = index - m;
						break;
					}

					if (!check(nr, nc, n, m)) continue;

					graph[index].push_back({ neighborIndex, 1 });
				}

				index++;
			}
		}
		int minCost = dijkstra(graph, n * m, 0);

		return minCost;
	}
};

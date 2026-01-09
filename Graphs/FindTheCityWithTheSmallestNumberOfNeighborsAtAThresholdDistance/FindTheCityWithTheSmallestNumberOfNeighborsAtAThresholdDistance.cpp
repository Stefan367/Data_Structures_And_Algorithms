// LeetCode problem: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Description: For each city, count how many other cities are reachable with shortest-path distance <= threshold.
//              Return the city with the smallest such count; if tie, return the city with the greatest index.
// Approach: Build an adjacency list and run Dijkstra from every city, then count reachable nodes within threshold.
// Time complexity: O(n * (E log V))
// Space complexity: O(V + E)

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

	int dijkstra(int start, int n, const vector<vector<Edge>>& graph, const int distanceThreshold)
	{
		vector<int> distances(n, INT_MAX);
		distances[start] = 0;

		priority_queue<Node> pq;
		pq.push({ start, 0 });

		int townsCount = 0;
		while (!pq.empty())
		{
			auto current = pq.top();
			pq.pop();

			if (current.distance > distances[current.index])
				continue;

			for (const auto& edge : graph[current.index])
			{
				int newWeight = current.distance + edge.weight;

				if (newWeight > distanceThreshold)
					continue;

				if (newWeight < distances[edge.to])
				{
					distances[edge.to] = newWeight;
					pq.push({ edge.to, newWeight });
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (distances[i] <= distanceThreshold)
			{
				townsCount++;
			}
		}
		return townsCount;
	}

	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
		vector<vector<Edge>> graph(n);

		for (int i = 0; i < (int)edges.size(); i++)
		{
			int from = edges[i][0];
			int to = edges[i][1];
			int weight = edges[i][2];

			graph[from].push_back({ to, weight });
			graph[to].push_back({ from, weight });
		}

		int maxTowns = INT_MAX;
		int indexToReturn = -1;
		for (int i = 0; i < n; i++)
		{
			int towns = dijkstra(i, n, graph, distanceThreshold);

			if (towns <= maxTowns)
			{
				indexToReturn = i;
				maxTowns = towns;
			}
		}
		return indexToReturn;
	}
};

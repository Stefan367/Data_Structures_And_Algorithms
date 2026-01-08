// LeetCode problem: 743. Network Delay Time
// Difficulty: Medium
// Link: https://leetcode.com/problems/network-delay-time/
// Description: Use Dijkstra from node k to compute shortest times to all nodes; answer is max distance (or -1 if unreachable).
// Time complexity: O((V + E) log E)
// Space complexity: O(V + E)

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>

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

	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		unordered_map<int, vector<Edge>> graph;

		for (int i = 0; i < (int)times.size(); i++)
		{
			int from = times[i][0];
			int to = times[i][1];
			int weight = times[i][2];

			from--;
			to--;

			graph[from].push_back({ to, weight });
		}

		vector<int> distances(n, INT_MAX);
		distances[k - 1] = 0;

		priority_queue<Node> pq;
		pq.push({ k - 1, 0 });

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

		int result = 0;
		for (int dist : distances)
		{
			if (dist == INT_MAX)
				return -1;

			result = max(result, dist);
		}

		return result;
	}
};

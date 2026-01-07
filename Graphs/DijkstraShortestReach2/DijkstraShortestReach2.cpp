// Platform: HackerRank
// Problem: Dijkstra: Shortest Reach 2
// Difficulty: Medium
// Link: https://www.hackerrank.com/challenges/dijkstrashortreach/problem
// Description: Compute shortest distances from a start node in an undirected weighted graph (multiple test cases).
// Time complexity: O((V + E) log E)
// Space complexity: O(V + E)

#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

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

vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
	unordered_map<int, vector<Edge>> graph;

	for (int i = 0; i < (int)edges.size(); ++i)
	{
		int from = edges[i][0];
		int to = edges[i][1];
		int weight = edges[i][2];

		from--;
		to--;

		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	vector<int> distances(n, INT_MAX);
	distances[s - 1] = 0;

	priority_queue<Node> nextToCome;
	nextToCome.push({ s - 1, 0 });

	while (!nextToCome.empty())
	{
		auto current = nextToCome.top();
		nextToCome.pop();

		if (current.distance > distances[current.index])
			continue;

		for (const auto& edge : graph[current.index])
		{
			int newWeight = current.distance + edge.weight;
			if (newWeight < distances[edge.to])
			{
				distances[edge.to] = newWeight;
				nextToCome.push({ edge.to, newWeight });
			}
		}
	}

	for (int& el : distances)
	{
		if (el == INT_MAX)
			el = -1;
	}

	distances.erase(distances.begin() + s - 1);

	return distances;
}

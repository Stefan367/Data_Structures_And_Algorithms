// Hackerrank contest problem: Safe Copying (minimum dangerous hints)
// Difficulty: Medium
// Link: https://www.hackerrank.com/contests/sda-homework-10/challenges/challenge-2748
// Description: Undirected graph with 0-cost (safe) edges and 1-cost (dangerous) edges.
//              Find the minimum number of dangerous hints needed so answers reach Eli in the safest way.
//              If unreachable, print -1.
// Approach: 0-1 shortest path (Dijkstra with 0/1 weights).
// Time complexity: O((N + E) log N)
// Space complexity: O(N + E)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int to;
	bool isDanger;
};

struct Node
{
	int index, distance;
	bool isDanger;

	friend bool operator<(const Node& a, const Node& b)
	{
		if (a.distance == b.distance)
		{
			return a.isDanger == 1;
		}
		return a.distance > b.distance;
	}
};

vector<int> dijkstra(int start, int n, const vector<vector<Edge>>& graph)
{
	vector<int> distances(n, INT_MAX);
	distances[start] = 0;

	priority_queue<Node> pq;
	pq.push({ start, 0, 0 });

	while (!pq.empty())
	{
		auto current = pq.top();
		pq.pop();

		if (current.distance > distances[current.index])
			continue;

		for (const auto& edge : graph[current.index])
		{
			int w = edge.isDanger ? 1 : 0;
			int newWeight = current.distance + w;

			if (newWeight < distances[edge.to])
			{
				distances[edge.to] = newWeight;
				pq.push({ edge.to, newWeight, edge.isDanger });
			}
		}
	}
	return distances;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<Edge>> graph(n);

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back({ to, 0 });
		graph[to].push_back({ from, 0 });
	}

	for (int i = 0; i < k; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back({ to, 1 });
		graph[to].push_back({ from, 1 });
	}

	int eli = 0, solver = n - 1;
	vector<int> distances = dijkstra(eli, n, graph);

	if (distances[solver] == INT_MAX)
		cout << -1;
	else
		cout << distances[solver];

	return 0;
}

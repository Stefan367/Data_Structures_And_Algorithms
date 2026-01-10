// Hackerrank contest problem: Shortest Paths 2 (Shortest distance + number of shortest paths)
// Difficulty: Medium (SDA HW)
// Link: https://www.hackerrank.com/contests/sda-hw-11-2021/challenges/shortest-paths-2
// Description: Given a directed weighted graph, find the length of the shortest path from node 1 to node n
//              and the number of distinct shortest paths (paths differ by at least one edge), modulo 1e9+7.
// Time complexity: O((V + E) log V)
// Space complexity: O(V + E)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct Edge
{
	int to;
	long long weight;
};

struct Node
{
	int index;
	long long distance;

	bool operator<(const Node& other) const
	{
		return distance > other.distance;
	}
};

const int MOD = 1e9 + 7;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<Edge>> graph(n);

	for (int i = 0; i < n; i++)
	{
		graph[i];
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		from--;
		to--;

		graph[from].push_back({ to, weight });
	}

	vector<long long> distances(n, LLONG_MAX);
	distances[0] = 0;

	vector<long long> ways(n, 0);
	ways[0] = 1;

	priority_queue<Node> pq;
	pq.push({ 0, 0 });

	while (!pq.empty())
	{
		auto current = pq.top();
		pq.pop();

		if (current.distance > distances[current.index])
			continue;

		for (const auto& edge : graph[current.index])
		{
			long long newWeight = current.distance + edge.weight;

			if (newWeight < distances[edge.to])
			{
				distances[edge.to] = newWeight;
				ways[edge.to] = ways[current.index];
				pq.push({ edge.to, newWeight });
			}
			else if (newWeight == distances[edge.to])
			{
				ways[edge.to] = (ways[current.index] + ways[edge.to]) % MOD;
			}
		}
	}

	if (distances[n - 1] == LLONG_MAX || ways[n - 1] == 0)
	{
		distances[n - 1] = -1;
		ways[n - 1] = 0;
	}
	cout << distances[n - 1] << " " << ways[n - 1];

	return 0;
}

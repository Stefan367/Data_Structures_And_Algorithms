// Hackerrank contest problem: long-long. (Longest Path in a Directed Weighted Graph, no positive cycles)
// Difficulty: Medium
// Link: https://www.hackerrank.com/contests/sda-hw-11/challenges/long-long/problem
// Description: Find the length of the longest path from s to t. If t is unreachable from s, print -1.
//              It is guaranteed there are no cycles with positive total weight.
// Idea: Convert longest path to shortest path by negating edge weights, then run Bellman-Ford from s.
// Time complexity: O(n * m)
// Space complexity: O(n + m)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge
{
	int from, to, weight;
};

vector<long long> bellman_ford(const vector<Edge>& edges, int start, int nodesCount)
{
	vector<long long> distances(nodesCount, LLONG_MAX);
	distances[start] = 0;

	for (int i = 0; i < nodesCount - 1; i++)
	{
		for (const auto& edge : edges)
		{
			if (distances[edge.from] != LLONG_MAX
				&& distances[edge.from] + edge.weight < distances[edge.to])
			{
				distances[edge.to] = distances[edge.from] + edge.weight;
			}
		}
	}

	return distances;
}

int main() {
	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	vector<Edge> edges;
	edges.reserve(m);

	for (int i = 0; i < m; i++)
	{
		int from, to, weight;
		std::cin >> from >> to >> weight;

		from--;
		to--;
		weight = -weight;

		edges.push_back({ from, to, weight });
	}

	vector<long long> distances = bellman_ford(edges, s - 1, n);

	if (distances[t - 1] == LLONG_MAX)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << -distances[t - 1];
	}
	return 0;
}

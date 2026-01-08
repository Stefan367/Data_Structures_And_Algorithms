// Hackerrank contest problem: 1-143. (Railways in Algorithmiya / Removable Rail Lines)
// Difficulty: Medium
// Link: https://www.hackerrank.com/contests/sda-hw-11/challenges/1-143/problem
// Description: Given undirected roads and rail lines from the capital to cities, remove the maximum number of rail lines
//              such that shortest distances from the capital to all cities do NOT increase.
// Time complexity: O((n + m + k) log (n + m + k))
// Space complexity: O(n + m + k)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
	int to, weight;
	bool isRail;
};

struct Node
{
	int index;
	long long distance;
	bool isRail;

	friend bool operator<(const Node& a, const Node& b)
	{
		if (a.distance == b.distance)
			return a.isRail == 1;

		return a.distance > b.distance;
	}
};

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	vector<vector<Edge>> graph(n);

	for (int i = 0; i < m; i++)
	{
		int from, to, weight;
		std::cin >> from >> to >> weight;
		from--;
		to--;

		graph[from].push_back({ to, weight, 0 });
		graph[to].push_back({ from, weight, 0 });
	}

	for (int i = 0; i < k; i++)
	{
		int to, weight;
		std::cin >> to >> weight;
		to--;

		graph[0].push_back({ to, weight, 1 });
		graph[to].push_back({ 0, weight, 1 });
	}

	// Djikstra
	vector<long long> distances(n, LLONG_MAX);
	distances[0] = 0;

	vector<bool> visited(n, false);

	priority_queue<Node> pq;
	pq.push({ 0, 0, 0 });

	int railsNeeded = 0;

	while (!pq.empty())
	{
		auto current = pq.top();
		pq.pop();

		if (!visited[current.index])
		{
			visited[current.index] = true;
			if (current.isRail) railsNeeded++;

			for (const auto& edge : graph[current.index])
			{
				long long newWeight = current.distance + edge.weight;

				if (newWeight <= distances[edge.to])
				{
					distances[edge.to] = newWeight;
					pq.push({ edge.to, newWeight, edge.isRail });
				}
			}
		}
	}

	std::cout << k - railsNeeded;

	return 0;
}

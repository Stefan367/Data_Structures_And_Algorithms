// Hackerrank contest problem: 2351. (Grafana Areas / Connected Components)
// Difficulty: (SDA contest) - Graph basics
// Link: https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2351/problem
// Description: Count connected components in an undirected graph for multiple test cases.
// Time complexity: O(X + Y) per test
// Space complexity: O(X + Y)



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

void dfs(int current, vector<bool>& visited, vector<vector<int>>& graph)
{
	visited[current] = true;

	for (int neighbor : graph[current])
	{
		if (!visited[neighbor])
		{
			dfs(neighbor, visited, graph);
		}
	}
}

int solve()
{
	int x, y;
	std::cin >> x >> y;

	vector<vector<int>> graph(x);

	int v, u;
	for (int e = 0; e < y; e++)
	{
		std::cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	vector<bool> visited(x, false);
	int count = 0;

	for (int i = 0; i < x; i++)
	{
		if (visited[i]) continue;

		dfs(i, visited, graph);
		count++;
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		int count = solve();
		std::cout << count << " ";
	}

	return 0;
}

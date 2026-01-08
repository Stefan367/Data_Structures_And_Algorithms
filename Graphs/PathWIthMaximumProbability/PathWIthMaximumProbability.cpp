// LeetCode problem: 1514. Path with Maximum Probability
// Difficulty: Medium
// Link: https://leetcode.com/problems/path-with-maximum-probability/
// Description: Find the maximum probability path between start_node and end_node in an undirected graph.
// Time complexity: O((V + E) log E)
// Space complexity: O(V + E)

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
	struct Edge
	{
		int to;
		double weight;
	};

	struct Node
	{
		int index;
		double distance;

		bool operator<(const Node& other) const
		{
			return distance < other.distance;
		}
	};

	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
		unordered_map<int, vector<Edge>> graph(n);

		for (int i = 0; i < edges.size(); i++)
		{
			int from = edges[i][0];
			int to = edges[i][1];
			double weight = succProb[i];

			graph[from].push_back({ to, weight });
			graph[to].push_back({ from, weight });
		}

		vector<double> distances(n, 0.0);
		distances[start_node] = 1.0;

		priority_queue<Node> nextToCome;
		nextToCome.push({ start_node, 1.0 });

		while (!nextToCome.empty())
		{
			auto currentNode = nextToCome.top();
			nextToCome.pop();

			if (currentNode.index == end_node)
				return currentNode.distance;

			if (currentNode.distance < distances[currentNode.index])
				continue;

			for (const auto& edge : graph[currentNode.index])
			{
				double newWeight = currentNode.distance * edge.weight;
				if (newWeight > distances[edge.to])
				{
					distances[edge.to] = newWeight;
					nextToCome.push({ edge.to, newWeight });
				}
			}
		}

		return 0.0;
	}
};

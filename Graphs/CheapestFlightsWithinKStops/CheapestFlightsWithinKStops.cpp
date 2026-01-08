// LeetCode problem: 787. Cheapest Flights Within K Stops
// Difficulty: Medium
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Description: Find the cheapest price from src to dst using at most k stops (i.e., at most k+1 flights).
// Idea: Bellman-Ford style DP with (k+1) relaxation rounds using a snapshot array (nextRow).
// Time complexity: O((k+1) * E)
// Space complexity: O(V)

#include <vector>
#include <climits>
#include <utility>

using namespace std;

class Solution {
public:
	struct Edge
	{
		int from, to, weight;
	};

	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<int> distances(n, INT_MAX);
		distances[src] = 0;

		for (int i = 0; i <= k; i++)
		{
			// nextRow is used to use the data from the previous row and not to work with just renewed values
			vector<int> nextRow(distances);

			for (const auto& flight : flights)
			{
				Edge edge({ flight[0], flight[1], flight[2] });

				if (distances[edge.from] != INT_MAX
					&& distances[edge.from] + edge.weight < nextRow[edge.to])
				{
					nextRow[edge.to] = distances[edge.from] + edge.weight;
				}
			}
			distances = std::move(nextRow);
		}

		return distances[dst] == INT_MAX ? -1 : distances[dst];
	}
};

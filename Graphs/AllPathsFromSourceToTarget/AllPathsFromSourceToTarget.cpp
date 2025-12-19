// LeetCode problem: 797. All Paths From Source to Target
// Difficulty: Medium
// Link: https://leetcode.com/problems/all-paths-from-source-to-target/
// Description: Given a directed graph (usually a DAG) as adjacency list, return all possible paths
//              from node 0 to node n-1 using DFS + backtracking.
// Time complexity: O(P * L) where P is the number of paths and L is the average path length
//                  (we copy each found path into the result).
// Space complexity: O(L) recursion stack + O(P * L) for storing all paths.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> result;

	void dfs(int current, vector<int>& path, const vector<vector<int>>& graph)
	{
		path.push_back(current);

		if (current == (int)graph.size() - 1)
		{
			result.push_back(path);
			path.pop_back();
			return;
		}

		for (int neighbor : graph[current])
		{
			dfs(neighbor, path, graph);
		}

		path.pop_back();
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		result.clear();
		vector<int> path;
		dfs(0, path, graph);
		return result;
	}
};

static void printPaths(const vector<vector<int>>& paths)
{
	cout << "[\n";
	for (const auto& p : paths) {
		cout << "  [";
		for (int i = 0; i < (int)p.size(); i++) {
			cout << p[i] << (i + 1 == (int)p.size() ? "" : ", ");
		}
		cout << "]\n";
	}
	cout << "]\n";
}

int main()
{
	Solution sol;

	vector<vector<int>> g1 = {
		{1, 2},
		{3},
		{3},
		{}
	};
	auto ans1 = sol.allPathsSourceTarget(g1);
	cout << "Test 1 result:\n";
	printPaths(ans1);
	cout << "Expected paths (order may differ): [[0,1,3],[0,2,3]]\n\n";

	vector<vector<int>> g2 = {
		{4, 3, 1},
		{3, 2, 4},
		{3},
		{4},
		{}
	};
	auto ans2 = sol.allPathsSourceTarget(g2);
	cout << "Test 2 result:\n";
	printPaths(ans2);
	cout << "Expected paths (order may differ): [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]\n\n";

	return 0;
}

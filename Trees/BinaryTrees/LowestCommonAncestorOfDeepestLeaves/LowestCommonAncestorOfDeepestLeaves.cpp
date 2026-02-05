/**
 * LeetCode Problem 1123: Lowest Common Ancestor of Deepest Leaves
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
 *
 * Idea:
 * DFS returns (candidateLCA, depth) for the subtree rooted at `current`.
 * - If left depth > right depth -> deepest leaves are in left subtree => propagate left's LCA, depth+1
 * - If right depth > left depth -> deepest leaves are in right subtree => propagate right's LCA, depth+1
 * - If equal depths -> deepest leaves exist in both subtrees => current is the LCA, depth+1
 *
 * Depth here is the height of the subtree (number of nodes on the longest path down), so null has depth 0.
 */

#include <utility>
using namespace std;

 //*
 // * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	std::pair<TreeNode*, int> dfs(TreeNode* current)
	{
		if (!current)
			return { nullptr, 0 };

		auto l = dfs(current->left);
		auto r = dfs(current->right);

		if (l.second > r.second)
		{
			return { l.first, l.second + 1 };
		}

		if (l.second < r.second)
		{
			return { r.first, r.second + 1 };
		}

		// same depth on both sides => current is LCA of deepest leaves in this subtree
		return { current, l.second + 1 };
	}

	TreeNode* lcaDeepestLeaves(TreeNode* root) {
		return dfs(root).first;
	}
};

// LeetCode Problem 199: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Description: Given the root of a binary tree, return the values of the nodes visible
// from the right side. Perform a level-order traversal (BFS) and record the last node
// at each depth.

#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (!root)
            return result;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty())
        {
            size_t levelSize = q.size();
            TreeNode* current = nullptr;

            while (levelSize > 0)
            {
                current = q.front();
                q.pop();

                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);

                levelSize--;
            }

            if (current)
            {
                result.push_back(current->val);
            }
        }

        return result;
    }
};

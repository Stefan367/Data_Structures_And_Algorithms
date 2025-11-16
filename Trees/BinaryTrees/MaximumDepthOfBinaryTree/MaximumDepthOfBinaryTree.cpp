// LeetCode Problem 104: Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Description: Find the maximum depth (height) of a binary tree.

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

#include <algorithm>
using namespace std;
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        int leftMaxDepth = maxDepth(root->left);
        int rightMaxDepth = maxDepth(root->right);

        return max(leftMaxDepth, rightMaxDepth) + 1;
    }
};

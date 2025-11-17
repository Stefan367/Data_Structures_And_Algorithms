// LeetCode Problem 700: Search in a Binary Search Tree
// Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
// Description: Given the root node of a binary search tree (BST) and an integer value,
// return the subtree rooted with the node whose value equals val. 
// If such a node does not exist, return null.

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return root;

        if (root->val == val)
            return root;

        if (root->val > val)
            return searchBST(root->left, val);
        else if (root->val < val)
            return searchBST(root->right, val);

        return root;
    }
};

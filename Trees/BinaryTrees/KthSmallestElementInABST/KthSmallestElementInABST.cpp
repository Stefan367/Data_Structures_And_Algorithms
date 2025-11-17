// LeetCode Problem 230: Kth Smallest Element in a BST
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Description: Given the root of a Binary Search Tree and an integer k,
// return the k-th smallest value in the tree (1-indexed).

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
    void inorder(TreeNode* root, int& k, int& value)
    {
        if (!root)
            return;

        if (k <= 0)
            return;

        inorder(root->left, k, value);

        k--;
        if (k == 0)
        {
            value = root->val;
        }

        inorder(root->right, k, value);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        inorder(root, k, result);

        return result;
    }
};

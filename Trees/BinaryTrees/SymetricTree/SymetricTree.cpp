// LeetCode Problem 101: Symmetric Tree
// Description: Given the root of a binary tree, check whether it is a mirror 
// of itself (i.e., symmetric around its center).
// Link: https://leetcode.com/problems/symmetric-tree/

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
    bool isSymetricHelp(TreeNode* left, TreeNode* right)
    {
        if (!left || !right)
            return left == right;

        if (left->val != right->val)
            return false;

        return (isSymetricHelp(left->left, right->right) &&
            isSymetricHelp(left->right, right->left));
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;

        return isSymetricHelp(root->left, root->right);
    }
};

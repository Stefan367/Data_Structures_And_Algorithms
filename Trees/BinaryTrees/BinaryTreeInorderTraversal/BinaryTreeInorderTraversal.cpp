// LeetCode Problem 94: Binary Tree Inorder Traversal
// Description: Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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

#include <vector>
using namespace std;

class Solution {
public:
    void inorder(TreeNode* current, vector<int>& inorderValues)
    {
        if (current != nullptr)
        {
            inorder(current->left, inorderValues);
            inorderValues.push_back(current->val);
            inorder(current->right, inorderValues);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};

// LeetCode Problem 897: Increasing Order Search Tree
// Link: https://leetcode.com/problems/increasing-order-search-tree/
// Description: Given the root of a binary search tree, rearrange the tree in in-order
// so that the leftmost node becomes the new root of the tree, and every node has no left child
// and only one right child.

#include <iostream>
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
    TreeNode* previous;

    void inorder(TreeNode* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);

            previous->right = root;
            root->left = nullptr;
            previous = root;

            inorder(root->right);
        }
    }

    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;

        TreeNode* dummy = new TreeNode(0);
        previous = dummy;

        inorder(root);

        TreeNode* newRoot = dummy->right;
        delete dummy;
        return newRoot;
    }
};

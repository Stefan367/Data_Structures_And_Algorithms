// LeetCode Problem 783: Minimum Distance Between BST Nodes
// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
// Description: Given the root of a Binary Search Tree (BST), return the minimum difference
// between the values of any two different nodes in the tree.


#include <climits>
#include <cmath>
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
    int currDif;
    int minDif;

    void inorder(TreeNode* current)
    {
        if (current == nullptr)
            return;

        inorder(current->left);

        if (previous)
        {
            currDif = abs(current->val - previous->val);
            if (minDif > currDif)
                minDif = currDif;
        }
        previous = current;

        inorder(current->right);
    }

    int minDiffInBST(TreeNode* root) {
        minDif = INT_MAX;
        inorder(root);
        return minDif;
    }
};

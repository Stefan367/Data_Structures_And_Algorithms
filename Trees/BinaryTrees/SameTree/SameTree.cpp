// LeetCode Problem 100: Same Tree
// Link: https://leetcode.com/problems/same-tree/
// Description:
// Given the roots of two binary trees p and q, write a function to check
// whether they are the same tree. Two binary trees are considered the same
// if they are structurally identical and the nodes have the same value.

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
    void preorder(TreeNode* p, TreeNode* q, bool& check)
    {
        if (!check) return;

        if (!p || !q)
        {
            check = (p == q);
            return;
        }

        if (p->val != q->val)
        {
            check = false;
            return;
        }

        preorder(p->left, q->left, check);
        preorder(p->right, q->right, check);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool check = true;
        preorder(p, q, check);
        return check;
    }
};

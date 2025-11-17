// LeetCode Problem 653: Two Sum IV - Input is a BST
// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Description: Given the root of a Binary Search Tree and an integer k,
// return true if there exist two elements in the BST such that their sum equals k.

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
    void inorder(TreeNode* root, vector<int>& vals)
    {
        if (!root)
            return;

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        vector<int> vals;
        inorder(root, vals);
        int i = 0, j = vals.size() - 1, sum = 0;

        while (i < j)
        {
            sum = vals[i] + vals[j];

            if (sum == k)
                return true;
            else if (sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};

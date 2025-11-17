// LeetCode Problem 538: Convert BST to Greater Tree
// Link: https://leetcode.com/problems/convert-bst-to-greater-tree/
// Description:
// Given the root of a Binary Search Tree (BST), convert it into a Greater Tree
// where each node's value is replaced by the sum of all values greater than or 
// equal to it in the original BST. The structure of the tree does NOT need to
// remain a valid BST after modification. The solution performs a reversed 
// in-order traversal (right -> root -> left), accumulating a running sum.

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
    void reverseOrder(TreeNode* root, int& sum)
    {
        if (!root)
            return;

        reverseOrder(root->right, sum);

        sum += root->val;
        root->val = sum;

        reverseOrder(root->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;

        int sum = 0;
        reverseOrder(root, sum);

        return root;
    }
};

// LeetCode Problem 1008: Construct Binary Search Tree from Preorder Traversal
// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
// Description: Given an array representing the preorder traversal of a BST,
// construct and return the corresponding BST.

#include <vector>;
#include <stack>
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0)
            return nullptr;

        stack<TreeNode*> nodes;

        TreeNode* root = new TreeNode(preorder[0]);
        nodes.push(root);

        TreeNode* parent = nullptr;
        int i = 1;

        while (i < preorder.size())
        {
            TreeNode* temp = new TreeNode(preorder[i]);

            if (preorder[i] < nodes.top()->val)
            {
                nodes.top()->left = temp;
                nodes.push(temp);
            }
            else
            {
                TreeNode* parent = nullptr;
                while (!nodes.empty() && preorder[i] > nodes.top()->val)
                {
                    parent = nodes.top();
                    nodes.pop();
                }
                parent->right = temp;
                nodes.push(temp);
            }
            i++;
        }

        return root;
    }
};

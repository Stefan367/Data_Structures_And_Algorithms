#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

// Simple TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// Build tree from level-order array (use -1 for null)
TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front(); q.pop();

        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Inorder print to visualize tree
void printInorder(TreeNode* node) {
    if (!node) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// ====== YOUR CODE (unchanged) ======
class Solution {
public:
    TreeNode* previous;

    void inorder(TreeNode* current, bool& check, const int k)
    {
        if (!current)
            return;

        previous = current;
        inorder(current->left, check, k);

        if (previous->val + current->val == k)
        {
            check = true;
            return;
        }

        inorder(current->right, check, k);
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        bool check = false;

        inorder(root, check, k);

        return check;
    }
};
// ===================================

// Test
int main() {
    // Example: [2,1,3]
    vector<int> v = { 2,1,3 };
    TreeNode* root = buildTree(v);

    cout << "Inorder traversal: ";
    printInorder(root);
    cout << "\n";

    Solution sol;
    sol.previous = nullptr;
    int k = 4;
    cout << "findTarget(k=" << k << ") = "
        << boolalpha << sol.findTarget(root, k) << "\n";

    return 0;
}

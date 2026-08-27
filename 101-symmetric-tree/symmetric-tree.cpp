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

    bool isMirror(TreeNode* left, TreeNode* right) {

        // Both are NULL
        if (left == nullptr && right == nullptr)
            return true;

        // One is NULL, other isn't
        if (left == nullptr || right == nullptr)
            return false;

        // Values must be equal
        if (left->val != right->val)
            return false;

        // Check mirror relationships
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr)
            return true;

        return isMirror(root->left, root->right);
    }
};
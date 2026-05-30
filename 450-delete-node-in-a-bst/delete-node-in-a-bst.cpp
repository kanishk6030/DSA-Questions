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
    TreeNode* minimum(TreeNode* root){
        TreeNode* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root == NULL)
            return NULL;

        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{

            // 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            // left child only
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // right child only
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 children
            TreeNode* succ = minimum(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right,succ->val);
        }

        return root;
    }
};
/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:

    // Traverse Left Boundary
    void traverseLeft(Node *root, vector<int> &ans) {

        // Base case
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;

        ans.push_back(root->data);

        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
    }

    // Traverse Leaf Nodes
    void traverseLeaf(Node *root, vector<int> &ans) {

        // Base case
        if(root == NULL)
            return;

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    // Traverse Right Boundary
    void traverseRight(Node *root, vector<int> &ans) {

        // Base case
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);

        // Push after recursion (reverse order)
        ans.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        // Base case
        if(root == NULL)
            return ans;

        ans.push_back(root->data);

        // Left Boundary
        traverseLeft(root->left, ans);

        // Leaf Nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        // Right Boundary
        traverseRight(root->right, ans);

        return ans;
    }
};
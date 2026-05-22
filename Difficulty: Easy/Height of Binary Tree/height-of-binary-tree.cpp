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
    int height(Node* root) {
        // code here
        // Whenn the code demands the edges then we should consider return -1 else for height in nodes then we should return 0;
        if(root == NULL) return -1;
        
        int left  = height(root -> left);
        
        int right = height(root -> right);
        
        // int ans = max( left , right) + 1; according to the question this is not correct
        int ans = max( left , right) + 1;
        
        return ans;
    }
};
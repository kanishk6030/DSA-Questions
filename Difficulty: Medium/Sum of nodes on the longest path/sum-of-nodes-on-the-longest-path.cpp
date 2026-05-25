/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    
    void solve(Node* root, int len, int sum,int &maxSum,int &maxLen){
        
        //base case 
        if(root == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen){
                maxSum = max(sum,maxSum);                
            }
            return;
        }
        
        sum += root->data;
        
        solve(root->left,len+1,sum,maxSum,maxLen);
        solve(root->right,len+1,sum,maxSum,maxLen);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int len = 0;
        int sum = 0;
        
        int maxLen = 0;
        int maxSum = INT_MIN;
        
        solve(root,len,sum,maxSum,maxLen);
        
        return maxSum;
    }
};
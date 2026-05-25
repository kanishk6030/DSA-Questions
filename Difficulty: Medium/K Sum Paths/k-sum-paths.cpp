/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void solve(Node* root,int k,int& count,vector<int>&path){
        //base case
        if(root == NULL){
            return;
        }
        path.push_back(root->data);
        
        //left
        solve(root -> left,k,count,path);
        //right
        solve(root -> right,k,count,path);
        
        //check for K  sum
        int sum = 0;
        int size = path.size();
        for(int i = size-1;i >= 0;i--){
            sum += path[i];
            if(sum==k){
                count ++ ;
            }
        }
        path.pop_back();
    }
    int countAllPaths(Node *root, int k) {
        // code here
        int count = 0;
        vector<int> path;
        solve(root,k,count,path);
        return count;
    }
};
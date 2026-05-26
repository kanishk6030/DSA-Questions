/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void createMapping(vector<int> inorder,map<int,int>&nodeToIndex,int n){
        for(int i = 0;i< n;i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node *solve(vector<int> &inorder, vector<int> &preorder,int &index,int inorderStart,int inorderEnd,int n,map<int,int>&nodeToIndex){
        //base case 
        if(index >= n || inorderStart > inorderEnd ){
            return NULL;
        }
        //Picking the first element from the preOrder and increasing the index by 1
        int element = preorder[index++];
        Node* root = new Node(element); //creating the node form the element we pick form the preeorder
        
        //Finding the index of the element on the Inorder
        int position = nodeToIndex[element];
        
        //recursive calls
        root->left = solve(inorder,preorder,index,inorderStart,position-1,n,nodeToIndex);
        
        root->right = solve(inorder,preorder,index,position+1,inorderEnd,n,nodeToIndex);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preOrderIndex = 0;
        int n = inorder.size();
        map<int,int> nodeToIndex;
        //call the mapping function to map the value
        createMapping(inorder,nodeToIndex,n);
        
        Node*ans = solve(inorder,preorder,preOrderIndex,0,inorder.size()-1,n,nodeToIndex);
        return ans;
    }
};
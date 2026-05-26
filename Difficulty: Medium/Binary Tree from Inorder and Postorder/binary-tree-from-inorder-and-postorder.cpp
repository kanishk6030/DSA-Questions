/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
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
    
    Node *solve(vector<int> &inorder, vector<int> &postorder,int &index,int inorderStart,int inorderEnd,int n,map<int,int>&nodeToIndex){
        //base case 
        if(index < 0 || inorderStart > inorderEnd ){
            return NULL;
        }
        //Picking the first element from the preOrder and increasing the index by 1
        int element = postorder[index--];
        Node* root = new Node(element); //creating the node form the element we pick form the preeorder
        
        //Finding the index of the element on the Inorder
        int position = nodeToIndex[element];
        
        //recursive calls
        root->right = solve(inorder,postorder,index,position+1,inorderEnd,n,nodeToIndex);
        
        root->left = solve(inorder,postorder,index,inorderStart,position-1,n,nodeToIndex);
        
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int postOrderIndex = postorder.size()-1;
        int n = inorder.size();
        map<int,int> nodeToIndex;
        //call the mapping function to map the value
        createMapping(inorder,nodeToIndex,n);
        
        Node*ans = solve(inorder,postorder,postOrderIndex,0,inorder.size()-1,n,nodeToIndex);
        return ans;
    }
};
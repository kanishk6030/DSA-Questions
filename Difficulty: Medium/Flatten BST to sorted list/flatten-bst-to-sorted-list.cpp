/*
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node* root,vector<int> &in){
    //Base Case
    if(root == NULL){
        return;
    }

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
    Node *flattenBST(Node *root) {
        // code here
         vector<int> inorderVal;
        inorder(root,inorderVal);
        int size = inorderVal.size();
        Node* newRoot = new Node(inorderVal[0]);
        Node* curr = newRoot;
//2nd step
        for(int i = 1;i < size;i++){
            Node* temp = new Node(inorderVal[i]);
            curr -> left = NULL;
            curr -> right = temp;
            curr = temp;
        }
//3rd step for the last node 
        curr -> left = NULL;
        curr -> right = NULL;

        return newRoot;
        
    }
};
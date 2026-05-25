/* Definition for Node
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
    Node* solve(Node* root,int &k,int node){
        //base case 
        if(root == NULL)return NULL;
        if(root -> data == node){
            return root;
        }
        
        Node* leftAns = solve(root->left,k,node);
        Node* rightAns = solve(root->right,k,node);
        
        //wapas ja arhe hai Upar yha se
        if(leftAns != NULL && rightAns ==NULL){
            k--;
            if(k<=0){
                //answer lock krdennge means kitna bhi upar jayega answer same rhega 
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }
        if(leftAns == NULL && rightAns !=NULL){
            k--;
            if(k<=0){
                //answer lock krdennge means kitna bhi upar jayega answer same rhega 
                k = INT_MAX;
                return root; //Yhi root ans hai ***
            }
            return rightAns;
        }
        return NULL;
        
    }
    int kthAncestor(Node *root, int k, int node) {
        // code here
        Node* ans = solve(root, k, node);

        // if ancestor doesn't exist
        if(ans == NULL || ans->data == node){
            return -1;
        }

        return ans->data;
    }
};

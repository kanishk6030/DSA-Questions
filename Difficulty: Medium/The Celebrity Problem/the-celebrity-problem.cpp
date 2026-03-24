class Solution {
  public:
  bool knows(vector<vector<int>>& mat,int a, int b, int n){
      if(mat[a][b] == 1){
          return true;
      }
      else{
          return false;
      }
  }
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> s;
        int n = mat.size();
        for(int i = 0;i< n;i++){
            s.push(i);
        }
        // Step 2 : check 2 index and compare
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(mat,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int ans  = s.top();
        // Step 3: single element om the stack is potential element so verify it
        
        //Row check
        int zeroCount = 0;
        for(int i = 0;i< n; i++){
            if(i != ans && mat[ans][i] == 0){
                zeroCount ++;
            }
        }
        if(zeroCount != n-1){
            return -1;
        }
        
        //Column check
        int oneCount = 0;
        for(int i = 0;i < n;i++){
            if(i != ans && mat[i][ans] == 1){
                oneCount ++;
            }
        }
        if(oneCount != n-1){
            return -1;
        }
        
        return ans;
    }
};
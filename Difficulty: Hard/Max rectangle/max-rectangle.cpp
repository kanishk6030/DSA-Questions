class Solution {
    private:
    
     vector<int> nextSmalerElements(vector<int> arr , int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmalerElements(vector<int> arr , int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = 0;i<n;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights,int n) {
      
       vector<int> next(n);

       next = nextSmalerElements(heights,n);

       vector<int> prev(n);

       prev = prevSmalerElements(heights,n);

       int area = INT_MIN;

       for(int i = 0; i< n;i++){
        int l = heights[i];
        if(next[i] == -1){
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area,newArea);
       }
       return area;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int rowSize = mat.size();
        int colSize = mat[0].size();
        int area = largestRectangleArea(mat[0],colSize);
        
        for(int i = 1 ; i < rowSize;i++){
            for(int j = 0; j < colSize;j++){
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                }
                else{
                    mat[i][j] = 0;
                }
            }
            area = max(area , largestRectangleArea(mat[i],colSize));
        }
        return area;
    }
};
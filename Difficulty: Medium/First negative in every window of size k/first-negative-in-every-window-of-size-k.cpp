class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();
        
        //process the first window
        for(int i = 0; i< k ; i++){
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }
        
        //store the ans of the first window
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        //process for remaining windows
        for(int i = k;i< n ;i++){
            //removal
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            
            //addition
            if(arr[i] < 0){
                dq.push_back(i);
            }
            
            //ans store 
            if(dq.size() > 0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
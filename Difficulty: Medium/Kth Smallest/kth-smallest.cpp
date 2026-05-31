class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        priority_queue<int> pq; // automatically return the max heap
        
        //step 1
        for(int i = 0;i < k;i++){
            pq.push(arr[i]);
        }
        
        //step2 Jo bakki bacha element hai usko push krna hai
        for(int i = k;i < arr.size(); i ++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //ans = pq.top()
        
        int ans = pq.top();
        return ans;
    }
};
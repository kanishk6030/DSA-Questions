class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        for(auto i:arr){
            minHeap.push(i);
        }
        
        int cost = 0;
        while(minHeap.size() > 1){
            int a = minHeap.top();
            minHeap.pop();
            
            int b = minHeap.top();
            minHeap.pop();
            
            int sum = a + b;
            
            cost += sum;
            
            minHeap.push(sum);
            
        }
        return cost;
        
    }
};
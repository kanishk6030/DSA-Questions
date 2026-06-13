class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> s;
        int N = nums.size();
        vector<int> ans(N);
        for(int i = 2*N - 1 ; i >=0 ;i--){
            while(!s.empty() && s.top() <= nums[i % N]){
                s.pop();
            }
            if(i < N){
                ans[i] = s.empty() ? -1 : s.top();
            }
            s.push(nums[i % N]);
        }
        return ans;
    }
};
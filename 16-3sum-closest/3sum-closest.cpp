class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left,right;
        int sum = 0;
        int diff = 0;
        int minDiff = INT_MAX;
        int ans = 0;
        for(int i = 0; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            left = i+1;
            right = n - 1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                diff = abs(sum - target);
                if(diff < minDiff){
                    minDiff = diff;
                    ans = sum;
                }
                if(sum < target){
                    left ++ ;
                }
                else if (sum > target){
                    right --;
                }
                else{
                    return ans;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int count = 0;
        int minSize = INT_MAX;
        int sum = 0;
        while( r < nums.size()){
                sum = sum + nums[r];
                r++;
                count++;

            while(sum >= target){
                minSize = min(minSize,count);
                sum = sum - nums[l];
                l++;
                count --;
            }
        }
        if(minSize != INT_MAX){
        return minSize;
        }
        else{
            return 0;
        }
    }
};
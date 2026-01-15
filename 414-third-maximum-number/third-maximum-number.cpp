class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max = LLONG_MIN;
        long secMax = LLONG_MIN;
        long thirdMax = LLONG_MIN;
        int distinct = 0;

        for (int i= 0 ;i < nums.size();i++){
            if(nums[i] == max || nums[i] == secMax || nums[i]==thirdMax){
                continue;
            }
            distinct ++;
            if(nums[i] > max){
                thirdMax = secMax;
                secMax = max;
                max = nums[i];
            }
            else if(nums[i] > secMax && nums[i] < max){
                thirdMax = secMax;
                secMax = nums[i];
            }
            else if(nums[i] > thirdMax && nums[i] < secMax){
                thirdMax = nums[i];
            }
        }
        
        return (distinct<3) ? max:thirdMax;
    }
};
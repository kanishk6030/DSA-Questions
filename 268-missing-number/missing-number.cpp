class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int totalSum = (nums.size()*(nums.size()+1))/2;
    int arrSum = 0;
    for(int i = 0;i < nums.size();i++){
        arrSum = arrSum + nums[i];
    }
    return totalSum - arrSum;
    }
};
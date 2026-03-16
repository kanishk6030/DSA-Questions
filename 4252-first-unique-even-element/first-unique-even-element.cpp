class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        map<int,int> freq;
        for(int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        //now check the first unique element
        for(int i = 0;i<nums.size();i++){
            if((nums[i]%2==0) && freq[nums[i]]==1){
                return nums[i];
            }
        }
        //No element is unique
        return -1;
    }
};
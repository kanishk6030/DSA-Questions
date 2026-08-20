class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> set;
        for(int i = 0 ; i < nums.size();i++){
            set.insert(nums[i]);
        }
        int current;
        int count = 0;
        int result;

        for(int num:set){
            if(set.find(num-1) == set.end()){
                current = num;
                count  = 1;
                while(set.find(current+1) != set.end()){
                    current ++;
                    count ++;
                }
                result = max(result, count);
            }
        }
        return result;
    }
};
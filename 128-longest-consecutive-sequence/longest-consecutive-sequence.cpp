class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        // unordered_set<int> set;
        // for(int i = 0 ; i < nums.size();i++){
        //     set.insert(nums[i]);
        // }
        // int current;
        // int count = 1;
        // int result;

        // for(int num:set){
        //     if(set.find(num-1) == set.end()){
        //         current = num;
        //         count  = 1;
        //         while(set.find(current+1) != set.end()){
        //             current ++;
        //             count ++;
        //         }
        //         result = max(result, count);
        //     }
        // }
        // return result;

        // Use sorting algo tc - O(n log n)
        sort(nums.begin(),nums.end());
        int count = 1;
        int result =1 ;
        for(int i= 1 ; i < nums.size();i++){
            if(nums[i] == nums[i - 1]){
                continue;
                //same number hai
            }
            if (nums[i - 1] + 1 == nums[i]){
                count ++;
            }
            else{
                count = 1;
            }
            result = max(result , count);
        }

        return result;
    }
};
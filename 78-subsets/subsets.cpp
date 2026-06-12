class Solution {
public:
    void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>& ans)
    {
        //base case
        if(index >= nums.size()){
            //answer bhejne se phele output ko answer me dalenge 
            ans.push_back(output);
            return;
        }

        //Recursive Call
        // Exclude
        solve(nums,output,index+1,ans);

        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums,output,index+1,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums,output,index,ans);
        return ans;
    }
};
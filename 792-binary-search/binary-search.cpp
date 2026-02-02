class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        int mid = st+(end-st)/2;
        while(st <= end){
            if(target == nums[mid]){
                return mid;
            }
            else if(target > nums[mid]){
                st = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            mid = st+(end-st)/2;
        }
    return -1;
    }
};
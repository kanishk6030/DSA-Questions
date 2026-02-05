class Solution {
public:
    int first(vector<int>& nums, int target){
        int st = 0;
        int end = nums.size()-1;
        int mid = st + (end - st)/2;
        int first = -1;
        while(st<=end){
            if(nums[mid] == target){
                first = mid;
                end = mid-1;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = st + (end - st)/2;
        }
        return first;
    }
    int last(vector<int>& nums, int target){
        int st = 0;
        int end = nums.size()-1;
        int mid = st + (end - st)/2;
        int last = -1;
        while(st<=end){
            if(nums[mid] == target){
                last = mid;
                st = mid+1;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = st + (end - st)/2;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOcc = first(nums,target);
        if(firstOcc == -1) return {-1,-1};
        int lastOcc = last(nums,target);
        return{firstOcc,lastOcc};
    }
};
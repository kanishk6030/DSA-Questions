class Solution {
  public:
    int first(vector<int>& arr, int target){
        int st = 0;
        int end = arr.size()-1;
        int mid = st + (end - st)/2;
        int first = -1;
        while(st<=end){
            if(arr[mid] == target){
                first = mid;
                end = mid-1;
            }
            else if(arr[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = st + (end - st)/2;
        }
        return first;
    }
    int last(vector<int>& arr, int target){
        int st = 0;
        int end = arr.size()-1;
        int mid = st + (end - st)/2;
        int last = -1;
        while(st<=end){
            if(arr[mid] == target){
                last = mid;
                st = mid+1;
            }
            else if(arr[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = st + (end - st)/2;
        }
        return last;
    }
    int countFreq(vector<int>& arr, int target) {
        int firstOcc = first(arr,target);
        if(firstOcc == -1) return 0;
        int lastOcc = last(arr,target);
        int count = (lastOcc - firstOcc)+1;
        return count;
        
    }
};

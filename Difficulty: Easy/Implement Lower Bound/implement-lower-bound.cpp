class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int st = 0;
        int end = arr.size()-1;
        int mid = st + (end-st)/2;
        int lb = arr.size();
        while(st <= end){
            if( arr[mid] >= target) {
                lb = mid;
                end=mid-1;
            }
            else st = mid + 1;
           mid = st + (end-st)/2;
        }
        return lb;
    }
};

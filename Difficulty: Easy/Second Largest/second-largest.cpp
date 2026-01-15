class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int max = INT_MIN;
        int secMax = INT_MIN;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] > max){
                secMax = max;
                max = arr[i];
            }
            else if(arr[i] > secMax && arr[i] < max){
                secMax = arr[i];
            }
        }
        if(secMax == INT_MIN){
            return -1;
        }
        return secMax;
    }
};
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> op;
        int j = 0;
        for(int i = 1;i<=n ;i++){
            if(j >= target.size()) break;
            op.push_back("Push");
             if(target[j] == i) {
                j++;  // move to next target element
            } else {
                op.push_back("Pop");
            }
        }
        return op;
    }
};
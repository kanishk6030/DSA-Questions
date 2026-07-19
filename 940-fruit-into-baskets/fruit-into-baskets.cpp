class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        unordered_map<int,int> map;
        int ans = INT_MIN;
        while( r < fruits.size()){
            map[fruits[r]]++;
            if(map.size() <= 2){
                //find ans
                ans = max(ans,r-l+1);
            }
            //this is when window is invalid
            while(map.size() > 2){
                map[fruits[l]]--;
                if(map[fruits[l]] == 0){
                    map.erase(fruits[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
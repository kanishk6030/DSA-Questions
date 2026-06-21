class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int iceCount = 0;
        long long price = 0;
        for(int i = 0;i<costs.size();i++){
            price += costs[i]; 
            if(price <= coins){
                iceCount++;
            }
        }
        return iceCount;
    }
};
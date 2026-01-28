class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minStock = INT_MAX;
        int maxStock = 0;
        for(int i = 0;i< prices.size();i++){
            
                minStock = min(minStock,prices[i]);
                maxStock = max(maxStock,prices[i]-minStock);
        }
    return maxStock;
    }
};
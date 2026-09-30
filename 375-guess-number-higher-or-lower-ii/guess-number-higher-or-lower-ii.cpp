class Solution {
public:
    int getMoneyAmount(int n) {

        vector<vector<int>> dp(n + 2,
                               vector<int>(n + 2, 0));

        // Length of range
        for (int len = 2; len <= n; len++) {

            for (int left = 1;
                 left + len - 1 <= n;
                 left++) {

                int right = left + len - 1;

                dp[left][right] = INT_MAX;

                // Try every possible guess
                for (int k = left; k <= right; k++) {

                    int leftCost = dp[left][k - 1];
                    int rightCost = dp[k + 1][right];

                    int cost = k + max(leftCost, rightCost);

                    dp[left][right] =
                        min(dp[left][right], cost);
                }
            }
        }

        return dp[1][n];
    }
};
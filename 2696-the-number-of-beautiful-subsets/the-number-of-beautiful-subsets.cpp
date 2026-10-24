class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            bool valid = true;

            for (int i = 0; i < n && valid; i++) {
                if (mask & (1 << i)) {
                    for (int j = i + 1; j < n; j++) {
                        if ((mask & (1 << j)) &&
                            abs(nums[i] - nums[j]) == k) {
                            valid = false;
                            break;
                        }
                    }
                }
            }

            if (valid) ans++;
        }

        return ans;
    }
};
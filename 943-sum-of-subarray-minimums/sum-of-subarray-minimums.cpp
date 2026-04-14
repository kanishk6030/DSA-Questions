class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Less Element (strictly less)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // Next Less or Equal Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long result = 0;

        for (int i = 0; i < n; i++) {
            long long contribution = (long long)arr[i] * left[i] * right[i];
            result = (result + contribution) % MOD;
        }

        return result;
    }
};
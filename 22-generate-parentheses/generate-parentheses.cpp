class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        // Base case: valid combination completed
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if possible
        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        // Add ')' if valid
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
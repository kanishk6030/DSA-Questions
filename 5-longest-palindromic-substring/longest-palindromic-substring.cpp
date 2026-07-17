class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {

        int n = s.size();

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (isPalindrome(s, i, j)) {

                    if (j - i + 1 > maxLen) {

                        maxLen = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
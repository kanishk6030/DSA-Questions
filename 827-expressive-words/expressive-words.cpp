class Solution {
public:
    bool isStretchy(string &s, string &word) {
        int i = 0, j = 0;

        while (i < s.size() && j < word.size()) {
            if (s[i] != word[j])
                return false;

            int cntS = 0, cntW = 0;
            char ch = s[i];

            while (i < s.size() && s[i] == ch) {
                cntS++;
                i++;
            }

            while (j < word.size() && word[j] == ch) {
                cntW++;
                j++;
            }

            if (cntS < cntW)
                return false;

            if (cntS != cntW && cntS < 3)
                return false;
        }

        return i == s.size() && j == word.size();
    }

    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;

        for (string &word : words) {
            if (isStretchy(s, word))
                ans++;
        }

        return ans;
    }
};
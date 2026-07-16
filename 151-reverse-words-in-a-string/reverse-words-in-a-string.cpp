class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string curr = "";

        for (char ch : s) {
            if (ch != ' ') {
                curr += ch;
            } else {
                if (!curr.empty()) {
                    words.push_back(curr);
                    curr.clear();
                }
            }
        }

        if (!curr.empty())
            words.push_back(curr);

        reverse(words.begin(), words.end());

        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += " ";
        }

        return ans;
    }
};
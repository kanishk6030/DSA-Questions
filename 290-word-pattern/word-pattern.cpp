class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        stringstream ss(s);

        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.length() != words.size())
            return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); i++) {

            char c = pattern[i];
            string w = words[i];

            // Character already mapped
            if (charToWord.count(c)) {
                if (charToWord[c] != w)
                    return false;
            }

            // Word already mapped
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c)
                    return false;
            }

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        vector<int> s1freq(26,0);
        vector<int> s2freq(26,0);

        for(int i = 0;i < s1.size();i++){
            s1freq[s1[i]-'a']++;
            s2freq[s2[i]-'a']++;
        }
        if(s1freq == s2freq) return true;

        for(int r = s1.size();r < s2.size();r++){
            s2freq[s2[r]-'a']++;
            s2freq[s2[r - s1.size()]-'a']--;

            if(s1freq == s2freq) return true;

        }

        return false;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> pFreq(26,0);
        vector<int> sFreq(26,0);
        
        if (s.size() < p.size()) return ans;
        
        for(int i = 0;i<p.size();i++){
             //increases the count
            pFreq[p[i]-'a']++;
            sFreq[s[i]-'a']++;
        }

        if(pFreq == sFreq) ans.push_back(0);

        for(int r = p.size(); r < s.size(); r++){
            sFreq[s[r] - 'a']++;
            sFreq[s[r - p.size()]-'a']--;

            if(pFreq == sFreq) ans.push_back(r - p.size() + 1);
        }

        return ans;
    }
};
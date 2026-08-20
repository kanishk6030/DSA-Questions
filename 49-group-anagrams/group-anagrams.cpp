class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , vector<string>> mp;
        for(auto st: strs){
            vector<int> freq(26,0);
            for(auto c : st){
                freq[c - 'a'] ++;
            }

            mp[freq].push_back(st);
        }

        vector<vector<string>> ans;
        for(auto& p:mp){
            ans.push_back(p.second);
        }

        return ans;
    }
};
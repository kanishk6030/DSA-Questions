class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0;i < s.size();i++){
            map1[s[i]]++;
            map2[t[i]]++;
        }
        if(map1 == map2){
            return true;
        }
    return false;
}};
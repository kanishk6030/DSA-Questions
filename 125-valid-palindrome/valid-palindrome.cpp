class Solution {
public:
    bool check( int i , int j , string &s )
    {
        if(i >= j)return true;
                if(!isalnum(s[i])){
                    i++;
                    return check(i,j,s);
                }
                if(!isalnum(s[j])){
                    j--;
                    return check(i,j,s);
                }
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }
                return check(i+1,j-1,s);
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        return check(i,j,s);
    }
}; 
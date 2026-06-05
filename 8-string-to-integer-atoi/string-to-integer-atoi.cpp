class Solution {
public:
    long long solve(string &s,int i, long long num, int sign){
        //as you get any alphabet return the number with sign
        if(i>=s.size() || !isdigit(s[i])){
            return num  * sign;
        }

        int digit = s[i] - '0';

        //overflow check
        if(sign == 1){
            if(num > INT_MAX/10 || (num == INT_MAX /10 && digit > 7 )){
                return INT_MAX;
            }
        }
        else{
            if(num > (long long)INT_MAX/10 || (num ==(long long)INT_MAX /10 && digit > 7 )){
                return INT_MIN;
            }
        }

        return solve(s,i+1,num*10+digit , sign);
    }

    int myAtoi(string s) {
        int i = 0;
        // eg : "   -123abc"
        //remove the spaces
        while(i < s.size() && s[i]==' '){
            i++;
        }

        //Deteremine the sign 
        int sign = 1;
        if(i < s.size() && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }

        //now we will make one fucniton 
        long long ans = solve(s,i,0,sign);


        if(ans > INT_MAX){
            return INT_MAX;
        }
        if(ans < INT_MIN){
            return INT_MIN;
        }
        return int(ans);

    }
};
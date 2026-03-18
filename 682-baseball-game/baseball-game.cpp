class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum = 0;
        for(int i= 0;i<operations.size();i++){
            string op = operations[i];
                if(op == "C"){
                    st.pop();
                }
                else if(op == "+"){
                    int num1 = st.top();
                    st.pop();
                    int num2 = st.top();
                    st.push(num1);
                    st.push(num1 + num2);
                }
                else if(op == "D"){
                    st.push(2 * st.top());
                }
                else{
                    int num= stoi(op);
                    st.push(num);
                }
        }
        while(!st.empty()){
            sum = sum + st.top();
            st.pop();
        }
    return sum;
    }
};
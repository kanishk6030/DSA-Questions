class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int i = 0; int j = 0;
        vector<int> c;
        
        while(i<a.size() && j<b.size()){
            if(a[i] < b[j]) {
                if(c.empty() || c.back()!= a[i]){
                c.push_back(a[i]);
                }
                i++;
            }
            else if(a[i] > b[j]){
                if(c.empty() || c.back() != b[j]){
                c.push_back(b[j]);
                }
                j++;
            }
            else {
                if(c.empty() || c.back() != a[i]){
                c.push_back(a[i]);
                }
                i++;
                j++;
            }
        }
        while(i< a.size()){
            if(c.empty() || c.back() != a[i]){
            c.push_back(a[i]);
            }
            i++;
        }
        while(j< b.size()){
            if(c.empty() || c.back() != b[j]){
            c.push_back(b[j]);
            }
            j++;
        }
    return c;
    }
};
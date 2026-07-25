class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            v.push_back(s[i] - '0');
        }
        int mx = INT_MIN;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                mx=max(mx,v[i]*v[j]);
            }
        }
        return mx;
    }
};
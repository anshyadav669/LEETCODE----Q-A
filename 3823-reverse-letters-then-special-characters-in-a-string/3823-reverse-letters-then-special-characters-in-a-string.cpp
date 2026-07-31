class Solution {
public:
    string reverseByType(string s) {
        string al = "", sp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                al += s[i];
            } else {
                sp += s[i];
            }
        }
        reverse(al.begin(), al.end());
        reverse(sp.begin(), sp.end());
        int j = 0, k = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = al[j];
                j++;
            } else {
                s[i] = sp[k];
                k++;
            }
        }
        return s;
    }
};
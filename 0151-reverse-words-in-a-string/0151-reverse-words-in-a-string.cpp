class Solution {
public:
    string reverseWords(string s) {
        vector<string> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            string a = "";
            int j = i;
            while (j < s.length() && s[j] != ' ') {
                a += s[j];
                j++;
            }
            while (j < s.length() && s[j] == ' ') {
                j++;
            }
            if (!a.empty()) {
                st.push_back(a);
            }
            i = j - 1;
        }

        int x = st.size();
        for (int i = x - 1; i >= 0; i--) {
            ans += st[i];
            if (i != 0) {
                ans += ' ';
            }
        }
        return ans;
    }
};
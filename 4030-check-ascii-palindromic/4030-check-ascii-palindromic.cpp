class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();
        string b = "";
        for(char c : s){
            int x = (int)c;

            for(int i=7; i>=0; i--){
                b += ((x >> i) & 1) + '0';
            }
        }
        int i = 0, j = b.size()-1;
        while (i < j) {
            if (b[i] != b[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
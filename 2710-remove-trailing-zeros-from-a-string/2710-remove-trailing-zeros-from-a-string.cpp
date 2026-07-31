class Solution {
public:
    string removeTrailingZeros(string num) {
        int cnt = 0;
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if (num[i] == '0') {
                cnt++;
            } else {
                break;
            }
        }
        num.erase(n - cnt, cnt);
        return num;
    }
};
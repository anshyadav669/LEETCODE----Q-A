class Solution {
public:
   string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.size()) 
        return s;

    string result;
    int cycleLen = 2 * numRows - 2; // one full zigzag cycle

    for (int row = 0; row < numRows; ++row) {
        for (int j = row; j < s.size(); j += cycleLen) {
            result += s[j];
            int diag = j + cycleLen - 2 * row;
            // middle characters in the zigzag (except first and last row)
            if (row != 0 && row != numRows - 1 && diag < s.size()) {
                result += s[diag];
            }
        }
    }
    return result;
}
};
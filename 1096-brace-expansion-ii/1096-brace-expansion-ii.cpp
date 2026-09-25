class Solution {
public:
    string s;
    int pos;

    set<string> parseExpression() {
        set<string> res;
        res.insert("");

        while (pos < s.size() && s[pos] != '}') {
            if (s[pos] == ',') {
                pos++;
                continue;
            }

            set<string> cur;

            if (s[pos] == '{') {
                pos++; // skip '{'
                cur = parseExpression();
                pos++; // skip '}'
            } 
            else {
                cur.insert(string(1, s[pos]));
                pos++;
            }

            // Concatenate current result with cur
            set<string> temp;

            for (auto &a : res) {
                for (auto &b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;

            // If next character is comma, union starts
            if (pos < s.size() && s[pos] == ',') {
                break;
            }
        }

        // Handle union
        while (pos < s.size() && s[pos] == ',') {
            pos++;

            set<string> next = parseExpression();

            res.insert(next.begin(), next.end());

            if (pos < s.size() && s[pos] == '}')
                break;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> ans = parseExpression();

        return vector<string>(ans.begin(), ans.end());
    }
};
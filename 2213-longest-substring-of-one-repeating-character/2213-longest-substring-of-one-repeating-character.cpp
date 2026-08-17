class Solution {
public:
    struct Node {
        int len;
        int pref, suff, best;
        char leftChar, rightChar;

        Node() {
            len = pref = suff = best = 0;
            leftChar = rightChar = '#';
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.pref = a.pref;
        if (a.pref == a.len && a.rightChar == b.leftChar) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;
        if (b.suff == b.len && a.rightChar == b.leftChar) {
            res.suff = b.len + a.suff;
        }

        // Best inside either side
        res.best = max(a.best, b.best);

        // Substring crossing the boundary
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node].len = 1;
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].best = 1;
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, ch);
        else
            update(2 * node + 1, mid + 1, r, idx, ch);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};
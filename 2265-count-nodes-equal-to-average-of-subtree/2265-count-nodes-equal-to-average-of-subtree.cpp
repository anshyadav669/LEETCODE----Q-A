/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        // Get sum and count of left subtree
        auto left = dfs(root->left);

        // Get sum and count of right subtree
        auto right = dfs(root->right);

        // Calculate current subtree sum and count
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Calculate floor average
        int average = sum / count;

        if (root->val == average) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
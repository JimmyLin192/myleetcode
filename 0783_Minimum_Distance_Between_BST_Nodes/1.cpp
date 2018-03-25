/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> s;
        TreeNode *cur = root, *prev = NULL;
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (prev) {
                ans = min(cur->val - prev->val, ans);
            }
            prev = cur;
            cur = cur->right;
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
        }
        return ans;
    }
};

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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        stack<TreeNode*> s;
        TreeNode *cur = root, *prev = NULL;
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (prev != NULL) {
                ans = min(ans, cur->val - prev->val);
            } 
            prev = cur;
            cur = cur->right;
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
        }
        return ans;
    }
};


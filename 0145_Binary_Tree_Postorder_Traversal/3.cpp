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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur = root;
        stack<TreeNode*> s; 
        while (true) {
            if (cur == NULL) {
                if (s.empty()) {
                    break;
                }
                cur = s.top();
                s.pop();
                cur = cur->left;
            } else {
                ans.push_back(cur->val);
                s.push(cur);
                cur = cur->right;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



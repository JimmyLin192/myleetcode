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
    vector<int> inorderTraversal(TreeNode* root) {
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
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                s.push(cur);
                cur = cur->left;
            }
        }
        return ans;
    }
};


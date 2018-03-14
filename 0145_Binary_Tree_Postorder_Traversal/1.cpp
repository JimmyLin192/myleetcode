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
        if (root != NULL) {
            helper(root, ans);
        }
        return ans;
    }
    void helper(TreeNode* root, vector<int>& ans) {
        if (root->left != NULL) {
            helper(root->left, ans);
        }
        if (root->right != NULL) {
            helper(root->right, ans);
        }
        ans.push_back(root->val);
        return ;
    }
};




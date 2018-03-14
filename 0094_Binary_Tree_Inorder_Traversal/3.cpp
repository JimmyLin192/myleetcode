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
        TreeNode *cur = root, *prev = NULL;
        while (cur != NULL) {
            if (cur->left == NULL) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;                    
                } else {
                    ans.push_back(cur->val);
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};



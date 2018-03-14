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
    void flatten(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode*> s;
        while (cur != NULL) {
            if (cur->left != NULL) {
                if (cur->right != NULL) {
                    s.push(cur->right);
                }
                cur->right = cur->left;
                cur->left = NULL;
            } else if (cur->right == NULL) {
                if (!s.empty()) {
                    cur->right = s.top();
                    s.pop();
                }
            }
            cur = cur->right;
        }
    }
};

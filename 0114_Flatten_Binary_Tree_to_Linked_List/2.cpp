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
        while (cur != NULL) {
            if (cur->left != NULL && cur->right != NULL) {
                TreeNode * t = cur->left;
                while (t->right != NULL) {
                    t = t->right;
                }
                t->right = cur->right;
                cur->right = NULL;
            }
            if (cur->left != NULL) {
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};


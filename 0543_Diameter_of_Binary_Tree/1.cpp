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
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterOfBinaryTreeHelper(root).second;
    }
    pair<int,int> diameterOfBinaryTreeHelper(TreeNode *root) {
        if (!root) {
            return {0,0};
        }
        pair<int,int> lr = diameterOfBinaryTreeHelper(root->left);
        pair<int,int> rr = diameterOfBinaryTreeHelper(root->right);
        int first = 0 , second = 0;
        int left_uni_max = lr.first + (root->left ? 1 : 0), 
            right_uni_max = rr.first + (root->right ? 1 : 0);
        first = max( left_uni_max, right_uni_max );
        second = max ( max( lr.second, rr.second), left_uni_max + right_uni_max );
        return { first , second };
    }
};

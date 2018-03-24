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
    int longestConsecutive(TreeNode* root) {
        return helper(root).second;
    }
    pair<int,int> helper(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        pair<int,int> ans = {1, 1}; 
        for (TreeNode* child : {root->left, root->right}) {
            if (!child) {
                continue;   
            }
            pair<int,int> ret = helper(child);    
            ans.first = max(ans.first, root->val + 1 == child->val ? ret.first + 1 : 1);
            ans.second = max(ans.second, max(ans.first, ret.second));
        }
        return ans;
    }
};

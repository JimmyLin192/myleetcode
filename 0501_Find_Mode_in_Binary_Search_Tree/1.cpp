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
    vector<int> findMode(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        unordered_map<int,int> freq;
        findModeHelper(root, freq);
        int max_freq = 0;
        for (auto& f : freq) {
            max_freq = max (f.second, max_freq);
        }
        vector<int> ans;
        for (auto& f : freq) {
            if (f.second == max_freq) {
                ans.push_back(f.first);
            }
        }
        return ans;
    }
    void findModeHelper(TreeNode* root, unordered_map<int,int>& freq) {
        if (root == NULL) {
            return ;
        }
        freq[root->val] ++;
        findModeHelper(root->left, freq);
        findModeHelper(root->right, freq);
    }
};



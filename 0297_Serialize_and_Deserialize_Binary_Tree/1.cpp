/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur) {
                ans += (ans.empty()?"":",") + to_string(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            } else {
                ans += ans.empty()?"n":",n";
            }
        }
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.front() == 'n') {
            return NULL;
        }
        int i = 0, n = data.size(), start = 0;
        queue<TreeNode*> q;
        while (i < n) {
            if (data[i++] == ',') {
                break;
            }
        }
        string str = string(data.begin(), data.begin()+i);
        TreeNode *root = str == "n" ? NULL : new TreeNode (stoi(str));
        if (!root) {
            return root;
        }
        q.push(root);
        TreeNode *cur = NULL;
        for ( start = i ; i <= n ; i ++ ) {
            if (i == n || data[i] == ',') {
                str = data.substr(start, i-start);
                TreeNode *res = str == "n" ? NULL : new TreeNode (stoi(str));
                if (!cur) {
                    cur = q.front();
                    q.pop();
                    cur->left = res;
                } else {
                    cur->right = res;
                    cur = NULL;
                }
                if (res) {
                    q.push(res);
                }
                start = i + 1;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

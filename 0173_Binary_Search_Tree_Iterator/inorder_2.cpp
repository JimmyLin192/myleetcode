/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    
    stack< pair<TreeNode*, bool>, list< pair<TreeNode*, bool> > > s;

    BSTIterator(TreeNode *root) {
        if (root != NULL) {
            s.push(make_pair(root, false));
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        int ans;
        while (true) {
            TreeNode *t = s.top().first;
            bool ready = s.top().second;
            s.pop();
            if (ready) {
                ans = t->val;
                break;
            } else {
                if (t->right != NULL) {
                    s.push(make_pair(t->right, false));
                }
                s.push(make_pair(t, true));
                if (t->left != NULL) {
                    s.push(make_pair(t->left, false));
                }
            }
        }
        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */





class Solution {
public:
    void generateParenthesisHelper(vector<string>& ans, string& cur, int left, int right) {
        if (!left && !right) {
            ans.push_back(cur);
            return;
        }
        if (left) {
            cur.push_back('(');
            generateParenthesisHelper(ans, cur, left-1, right+1);
            cur.pop_back();
        }
        if (right) {
            cur.push_back(')');
            generateParenthesisHelper(ans, cur, left, right-1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        generateParenthesisHelper(ans, cur, n, 0);
        return ans;
    }
};

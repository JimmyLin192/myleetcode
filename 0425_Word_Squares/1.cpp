class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> ans;
        int n = words.size();
        if (!n) {
            return ans;
        }
        vector<string> cur;
        unordered_map<string, vector<string>> prefixmap;
        prefixmap[""] = words;
        for (string w : words) {
            for (int j = 1 ; j <= w.size(); j ++) {
                prefixmap[w.substr(0,j)].push_back(w);
            }
        }
        helper(words, prefixmap, ans, cur);
        return ans;
    }
    
    void helper (vector<string>& words, unordered_map<string, vector<string>>& prefixmap,
                 vector<vector<string>>& ans, vector<string>& cur) {
        if (cur.size() == words.front().size()) {
            ans.push_back(cur);
            return ;
        } else if (cur.size() > words.front().size()) {
            return ;
        }
        string prefix = "";
        for (int i = 0 ; i < cur.size(); i ++) {
            prefix += cur[i][cur.size()];
        }
        for (string w : prefixmap[prefix]) {
            cur.push_back(w);
            bool check = true;
            for (int j = 0; j < cur.size(); j ++) {
                if (cur[cur.size()-1][j] != cur[j][cur.size()-1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                helper(words, prefixmap, ans, cur);
            }
            cur.pop_back();
        }
    }
};

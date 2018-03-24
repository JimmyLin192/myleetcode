class Solution {
public:
    vector<string> book = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ans; 
        string combo = "";
        helper(ans, digits, combo, 0);
        return ans;
    }
    void helper (vector<string>& ans, string& digits, string& combo, int idx) {
        if (idx == digits.size()) {
            ans.push_back(combo);
            return;
        }
        for (char x : book[digits[idx]-'0']) {
            combo += x;
            helper(ans, digits, combo, idx+1);
            combo.pop_back();
        }
        return;
    }
};

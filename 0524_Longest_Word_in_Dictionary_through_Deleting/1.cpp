class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = s.size(), longest = 0;
        string ans = "";
        if (!n) {
            return ans;
        }
        for (string& str : d) {
            if (str.size() < longest) {
                continue;
            }
            if (matched(s, str)) {
                if (str.size() > longest || (str.size() == longest && str < ans) ) {
                    ans = str;
                    longest = (int) str.size();
                }
            }
        }
        return ans;
    }
    bool matched(string& s, string& str) {
        int n = s.size(), m = str.size();
        int j = 0;
        for (int i = 0 ; i < n && j < m ; i++) {
            if (s[i] == str[j]) {
                j ++;
            }
        }
        return j == m;
    }
};

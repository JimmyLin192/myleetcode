class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if (n == 0) {
            return -1;
        } else if (n == 1) {
            return 0;
        }
        vector<int> counter(26, 0);
        for (int i = 0; i < n; i ++) {
            if (isLower(s[i])) {
                counter[s[i]-'a']++;
            }
        }
        for (int i = 0; i < n; i ++) {
            if (counter[s[i]-'a'] < 2) {
                return i;
            }
        }
        return -1;
    }
    bool isLower (char x) {
        return 'a' <= x && x <= 'z';
    }
};

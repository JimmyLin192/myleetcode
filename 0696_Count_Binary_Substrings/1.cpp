class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        if (n <= 1) {
            return 0;
        }
        int count = 0;
        for (int i = 1; i < n; i ++) {
            if (s[i] != s[i-1]) {
                count ++;
                helper(s, i-2, i+1, count);
            }
        }
        return count;
    }
    void helper(string& s, int left, int right, int& count) {
        int n = s.size();
        if (left < 0 || right >= n) {
            return ;
        }
        while (s[left] == s[left+1] && s[right] == s[right-1]) {
            count ++;
            left --;
            right ++;
            if (left < 0 || right >= n) {
                return ;
            }
        }
    }
};

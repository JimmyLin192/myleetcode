class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        while (i < j) {
            while (i < j && !isAlphaNumeric(s[i])) {
                i ++;
            }
            while (i < j && !isAlphaNumeric(s[j])) {
                j --;
            }
            if (isUpper(s[i])) {
                s[i] += 'a' - 'A';
            }
            if (isUpper(s[j])) {
                s[j] += 'a' - 'A';
            }
            if (s[i] != s[j]) {
                return false;
            } 
            i ++, j --;
        }
        return true;
    }
    bool isAlphaNumeric(char x) {
        return 'a' <= x && x <= 'z' ||
               isUpper(x) ||
               '0' <= x && x <= '9';
    }
    bool isUpper(char x) {
        return 'A' <= x && x <= 'Z';
    }
};

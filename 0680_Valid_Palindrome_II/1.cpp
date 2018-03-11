class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(); 
        if (n <= 1) return true;
        return validPalindromeHelper(s, 0/*start*/, n-1/*end*/, 0/*removed*/);
    }
    bool validPalindromeHelper(string& s, int left, int right, int removed) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (removed >= 1) {
                    return false;
                }
                return validPalindromeHelper(s, left+1, right, removed+1) || 
                    validPalindromeHelper(s, left, right-1, removed+1);
            }
            left ++, right--;
        }
        return true;
    }
};


class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        bool rev = true;
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (++count == k || i == n - 1) {
                if (rev) {
                    reverse(s.begin()+i-count+1, s.begin()+i+1);
                }
                rev = !rev;
                count = 0;
            }
        }
        return s;
    }
};

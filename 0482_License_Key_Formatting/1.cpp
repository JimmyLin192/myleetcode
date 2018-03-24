class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
        int i = 0;
        for (auto iter = S.rbegin(); iter != S.rend(); iter ++) {
            if (*iter == '-') {
                continue;
            }
            if (i == K) {
                ans.push_back('-');
                i = 0;
            }
            ans.push_back(toUpperIfLower(*iter));
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    char toUpperIfLower(char x) {
        if ('a' <= x && x <= 'z') {
            return x - 'a' + 'A';
        } else {
            return x;
        }
    }
};

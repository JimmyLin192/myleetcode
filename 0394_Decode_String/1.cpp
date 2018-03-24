class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        string ans = "";
        for (int i = 0, start = 0; i < n ; i ++) {
            if (s[i] == '[') {
                int times = stoi(s.substr(start, i-start));
                int count = 1, k = i + 1;
                for ( ; k < s.size() && count > 0; k ++) {
                    if (s[k] == '[') {
                        count ++;
                    } else if (s[k] == ']') {
                        count --;
                    }
                }
                k--;
                string data = decodeString(s.substr(i+1, k-i-1));
                while (times --) {
                    ans += data;
                }
                i = k;
                start = i + 1;
            } else if (!isdigit(s[i])) {
                ans += s[i];
                start = i + 1;
            }
        }
        return ans;
    }
};

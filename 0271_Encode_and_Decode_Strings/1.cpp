class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size(); 
        string ans = "";
        for (string& str : strs) {
            ans += to_string(str.size()) + "@" + str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans; 
        int n = s.size();
        int start = 0;
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == '@') {
                int len = stoi(s.substr(start, i));
                ans.push_back(s.substr(i+1, len));
                i += len;
                start = i + 1;
            }           
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> mp;
        for (string str : strings) {
            string key = "";
            if (!str.empty()) {                
                int offset = str.front() - 'a';
                for (char x : str) {
                    int c = x - offset;
                    key += c < 'a' ? c + 26: c ;
                }
            }
            if (mp.count(key)) {
                mp[key].push_back(str);
            } else {
                mp[key] = {str};
            }
        }
        vector<vector<string>> ans;
        for (auto& p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

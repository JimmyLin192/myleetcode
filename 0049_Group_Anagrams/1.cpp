class Solution {
public:
    string counting_sort(string& str) {
        string res (str.size(),' ');
        vector<int> freq (26, 0);
        for (char x : str) {
            freq[x-'a']++;
        }
        int write_index = 0;
        for (int i = 0 ; i < 26 ; i ++) {
            while (freq[i]--) {
                res[write_index++] = 'a' + i;
            }
        }
        return res;
    } 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string str : strs) {
            string key = counting_sort(str);
            if (mp.count(key)) {
                mp[key].push_back(str);
            } else {
                mp[key] = {str};
            }
        }
        vector<vector<string>> ans;
        for (auto p : mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

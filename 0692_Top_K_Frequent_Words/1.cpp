struct comp {
    bool operator() (const pair<string,int>& lhs, const pair<string,int>& rhs) {
        return (lhs.second < rhs.second) || (lhs.second == rhs.second && lhs.first.compare(rhs.first) > 0);
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        if (n == 0) {
            return vector<string>();
        }
        unordered_map<string, int> records;
        for (int i = 0; i < n; i ++) {
            records[words[i]] ++;
        }
        priority_queue<pair<string, int>, vector< pair<string, int> >, comp> maxHeap;
        for (auto& r : records) {
            maxHeap.push(r);
        }
        vector<string> ans;
        while (!maxHeap.empty() &&  (int)ans.size() < k) {
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;
    }
};



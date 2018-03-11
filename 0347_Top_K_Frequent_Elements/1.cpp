class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.empty()) {
            return vector<int>();
        }
        // phase one: item count
        unordered_map<int, int> item_counts;
        for (int num : nums) {
            item_counts[num] ++;
        }
        // phase two: priority queue
        auto comp = [] (const pair<int,int>& a, const pair<int,int>& b) -> bool {
            return a.second > b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue< pair<int,int>, vector< pair<int,int> >, decltype(comp)> min_heap(comp); 
        for (auto& ic : item_counts) {
            min_heap.push(ic);
            if ((int) min_heap.size() > k) {
                min_heap.pop();
            }
        }
        // phase three: output remainders in priority queue
        vector<int> ans;
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().first);
            min_heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

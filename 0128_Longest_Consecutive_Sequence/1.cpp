class Solution {
public:
    // using unordered set and bi-directional linear search 
    // O(n) time complexity and O(n) space complexity
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }
        int longest = 0;
        while (!s.empty()) {
            int x = *s.begin();
            s.erase(x);
            int length = 1, cur = x;
            while (!s.empty() && s.count(++cur)) {
                s.erase(cur);
                length++;
            }
            cur = x;
            while (!s.empty() && s.count(--cur)) {
                s.erase(cur);
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};

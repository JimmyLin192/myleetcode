class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k < 0) {
            return -1;
        }
        set<int> s;
        int target = k + 1;
        for (int i = 0 ; i < n ; i ++) {
            set<int>::iterator iter = s.insert(flowers[i]).first;
            if (iter != s.begin() && *iter - *prev(iter) == target ||
                next(iter) != s.end() && *next(iter) - *iter == target) {
                return i+1;
            }
        }
        return -1;
    }
};

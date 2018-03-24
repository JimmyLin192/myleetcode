class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int acc = 1;
        for (auto& d = digits.rbegin(); acc > 0 && d != digits.rend(); d ++) {
            int dsum = *d + acc;
            *d = dsum % 10, acc = dsum / 10;
        }
        if (acc > 0) {
            digits.push_front(acc);
        }
        return digits;
    }
};

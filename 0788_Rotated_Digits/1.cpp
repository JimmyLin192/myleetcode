class Solution {
public:
    bool isValid (int val) {
        bool result = false;
        while (val > 0) {
            int last = val % 10; 
            if (last == 3 || last == 4 || last == 7) {
                return false;
            } else if (last == 2 || last == 5 || last == 6 || last == 9) {
                result = true;
            }
            val /= 10;
        }
        return result;
    }
    int rotatedDigits(int N) {
        int count = 0;
        for (int val = 1; val <= N; val ++) {
            if (isValid(val)) {
                count ++; 
            }
        }
        return count;
    }
};

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty()) {
            return true;
        }
        int size = data.size();
        for (int i = 0 ; i < size; i ++) {
            int n;
            if ( !(data[i] & (1 << 7) ) ) {
                n = 1;
            } else if ( ((data[i] >> 5) & 7) == 6 ) {
                n = 2;
            } else if ( ((data[i] >> 4) & 15) == 14 ) {
                n = 3;
            } else if ( ((data[i] >> 3) & 31) == 30 ) {
                n = 4;
            } else {
                return false;
            }
            for (int k = 1; k <= n-1; k ++) {
                if ( i + k >= size) {
                    return false;
                }
                if ( (data[i+k] & (3 << 6)) != (2 << 6) ) {
                    return false;
                }
            }
            i += n - 1;
        }
        return true;
    }
};

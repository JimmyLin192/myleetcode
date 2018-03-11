class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n <= 1) {
            return n; 
        }
        int write_index = 1;
        int count = 1;
        for (int i = 1; i <= n; i ++) {
            if (i == n || chars[i] != chars[i-1]) {
                if (count > 1) {
                    int begin_index = write_index;
                    while (count > 0) {
                        chars[write_index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(chars.begin()+begin_index, chars.begin()+write_index);
                }
                if (i != n) {
                    chars[write_index++] = chars[i];
                    count = 1;
                }
            } else {
                count ++;
            }
        }
        return write_index;
    }
};

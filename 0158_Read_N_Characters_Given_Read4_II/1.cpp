// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char intern_buf[4];
    int ibi = 0, ibn = 0;
    int read(char *buf, int n) {
        int i = 0;
        while (i < n) {
            while (i < n && ibi < ibn) {
                *(buf+i) = intern_buf[ibi];
                i++, ibi++;
            }
            if (i == n) {
                break;
            }
            ibi = 0, ibn = read4(intern_buf);
            if (!ibn) {
                break;
            }
        }
        return i;
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n = A.size(), m = B.size();
        string exA = string(A);
        int count = 1;
        while (exA.size() < B.size()) {
            exA += A;
            count ++;
        }
        if (exA.find(B) != string::npos) {
            return count;
        }
        exA += A;
        count ++;
        if (exA.find(B) != string::npos) {
            return count;
        }
        return -1;
    }
};

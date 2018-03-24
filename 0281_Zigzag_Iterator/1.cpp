class ZigzagIterator {
public:
    
    bool v1_ready;
    vector<int>::iterator v1_iter, v2_iter, v1_end, v2_end;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        v1_ready = true;
        v1_iter = v1.begin();
        v2_iter = v2.begin();
        v1_end = v1.end();
        v2_end = v2.end();
    }

    int next() {
        int ans;
        if ((v1_ready || v2_iter == v2_end) && v1_iter != v1_end) {
            ans = *(v1_iter++);
        } else {
            ans = *(v2_iter++);
        }
        v1_ready = !v1_ready;
        return ans;
    }

    bool hasNext() {
         return v1_iter != v1_end || v2_iter != v2_end;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

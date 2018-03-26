class Vector2D {
public:
    vector<vector<int>>::iterator vec_iter, vec_iter_end;
    vector<int>::iterator int_iter, int_iter_end;
    Vector2D(vector<vector<int>>& vec2d) {
        vec_iter = vec2d.begin();
        vec_iter_end = vec2d.end();
        while (vec_iter != vec_iter_end && vec_iter->empty()) {
            vec_iter++;
        }
        if (vec_iter != vec_iter_end) {
            int_iter = vec_iter->begin();
            int_iter_end = vec_iter->end();
        }
    }

    int next() {
        int ans = *int_iter;
        if (++ int_iter == int_iter_end) {
            vec_iter ++;
            while (vec_iter != vec_iter_end && vec_iter->empty()) {
                vec_iter++;
            }
            if (vec_iter != vec_iter_end) {
                int_iter = vec_iter->begin();
                int_iter_end = vec_iter->end();
            }
        }
        return ans;
    }

    bool hasNext() {
        return vec_iter != vec_iter_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

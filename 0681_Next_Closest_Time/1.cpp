class Solution {
public:
    string nextClosestTime(string time) {
        set<char> s;
        for (char x : time) {
            if (x != ':') {
                s.insert(x);
            }
        }
        string closest = string(time);
        int mtime = get_mtime(time), min_mtime = INT_MAX;
        string cur = "";
        for (char h1 : s) {
            if (h1 > '2') {
                continue;
            }
            cur += h1;
            for (char h2 : s) {
                if (h1 == '2' && h2 > '3') {
                    continue;
                }
                cur += h2;
                cur += ':';
                for (char m1 : s) {
                    if (m1 > '5' || m1 < '0') {
                        continue;
                    }
                    cur += m1;
                    for (char m2 : s) {
                        cur += m2;
                        if (cur == time) {
                            cur.pop_back();
                            continue;
                        }
                        int mcurtime = get_mtime(cur);
                        int mtdiff = mcurtime-mtime;
                        for (int td : {mtdiff, mtdiff+24*60} ) {
                            if (td < 0) {
                                continue;
                            }
                            if (td < min_mtime) {
                                closest = cur;
                                min_mtime = td;
                            }
                        }
                        cur.pop_back();
                    }
                    cur.pop_back();
                }
                cur.pop_back();
                cur.pop_back();
            }
            cur.pop_back();
        }
        return closest;
    }
    int get_mtime(string cur) {
        return ((cur[0]-'0') * 10 + (cur[1]-'0')) * 60 + (cur[3]-'0')*10 + cur[4]-'0';
    }
};

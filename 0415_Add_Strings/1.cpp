class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        auto iter1 = num1.begin(), iter2 = num2.begin();
        int acc = 0;
        while (iter1 != num1.end() || iter2 != num2.end()) {
            int a1 = iter1 == num1.end() ? 0 : ((*iter1)-'0');
            int a2 = iter2 == num2.end() ? 0 : ((*iter2)-'0');
            int sum = acc + a1 + a2;
            ans.push_back('0' + (sum % 10));
            acc = sum / 10;
            if (iter1 != num1.end()) {
                iter1 ++;
            }
            if (iter2 != num2.end()) {
                iter2 ++;
            }
        }
        if (acc) {
            ans.push_back('0' + acc);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int prev_min_price = prices[0];
        int max_profit = 0;
        for (int i = 1 ; i < (int) prices.size() ; i ++) {
            max_profit = max (max_profit, prices[i]-prev_min_price);
            prev_min_price = min ( prev_min_price, prices[i]);
        }
        return max_profit;
    }
};

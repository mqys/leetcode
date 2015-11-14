class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // attention to buy and sell order
        if (prices.size() < 1) return 0;
        int buy = prices[0], sell = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // when min update, price[i] don't have be greater than max to get the maxprofit
            if (prices[i] > buy && prices[i] - buy > profit) { 
                sell = prices[i];
                profit = sell - buy;
            }
            if (prices[i] < buy) {
                buy = prices[i];
            }
        }
        return profit;
    }
};
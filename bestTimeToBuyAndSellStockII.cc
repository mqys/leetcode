class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // think about the line prices go, and get exery increasing line, then that is the max profit
        // use future price, if today price goes down, sold it yesterday
        int sum = 0;
        if (prices.size() < 1) return sum;
        int buy = INT_MAX, sell = buy;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < sell) {
                sum += sell - buy;
                buy = prices[i];
                sell = buy;
            }
            if (prices[i] > sell) {
                sell = prices[i];
            }
        }
        sum += sell - buy; // if increase at the end, then sell it 
        return sum;
    }
};
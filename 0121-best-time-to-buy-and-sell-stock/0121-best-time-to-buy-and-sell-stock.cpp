class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_to_buy = prices[0];
        int max_profit = 0;
        int cur_profit;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]-min_to_buy<=0) cur_profit = 0;
            else cur_profit = prices[i]-min_to_buy;
            max_profit = max(max_profit, cur_profit);
            min_to_buy = min(min_to_buy, prices[i]);
        }
        return max_profit;
    }
};
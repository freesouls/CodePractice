class Solution {
public:

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        if (k >= n) return maxProfit(prices);
        int local[k+1] = {0};
        int global[k+1] = {0};
        
        for (int i=0; i < n - 1; i++){
            int diff = prices[i+1] - prices[i];
            for (int j = k; j>=1; j--){
                local[j] = max(global[j-1]+(diff > 0? diff:0), local[j]+diff);
                global[j] = max(global[j], local[j]);
            }
        }
        
        return global[k];
    }
    
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
    
};
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
            //http://blog.csdn.net/foreverling/article/details/43911309
            // 
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



/* for large K, time exceed!!!
class Solution {
public:
    int max_res = 0;
    int n = 0;
    int kk = 0;
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        if (n < 2) return 0;
        max_res = 0;
        kk = k;
        int res = 0;
        int start = 0;
        
        maxProfit(prices, res, start, 0);
        return max_res;
    }
    
    void maxProfit(vector<int>& prices, int res, int start, int k){
        if (k == kk || start >= n - 1) {
            max_res = max(max_res, res);
            return;
        }
        
        int min_price = prices[start];
        int profit = 0;
        for (int i = start + 1; i < prices.size(); i++){
            profit = max(profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
            res += profit;
            maxProfit(prices, res, i, k+1);
            res -= profit;
        }
    }
};
*/

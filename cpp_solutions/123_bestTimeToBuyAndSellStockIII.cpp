class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        
        vector<int> front(n, 0);
        vector<int> back(n, 0);
        int min_price = prices[0];
        for (int i = 1; i < n; i++){
            front[i] = max(front[i - 1], prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        
        int max_price = prices[n - 1];
        for (int i = n - 2; i >=0; i--){
            back[i] = max(back[i + 1], max_price - prices[i]);
            max_price = max(max_price, prices[i]);
        }
        int max_res = 0;
        for (int i = 0; i < n; i++){
            max_res = max(max_res, front[i] + back[i]);
        }
        
        return max_res;
    }
};
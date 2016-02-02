// https://leetcode.com/discuss/71354/share-my-thinking-process
// https://leetcode.com/discuss/72030/share-my-dp-solution-by-state-machine-thinking
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int buy = INT32_MIN, sell = 0, prev_sell = 0, prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = std::max(prev_sell - price, buy);
            prev_sell = sell;
            sell = std::max(prev_buy + price, sell);
        }
        return sell;
    }
};

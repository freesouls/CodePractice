class Solution {
public:
    /**
     * @param costs n x 3 cost matrix
     * @return an integer, the minimum cost to paint all houses
     */
    /*
    r means min cost when painting current house red
    */
    int minCost(vector<vector<int>>& costs) {
        // Write your code here
        int r = 0, g = 0, b = 0;
        for (int i = 0; i < costs.size(); i++) {
            int rr = r, gg = g, bb = b;
            r = costs[i][0] + min(gg, bb);
            g = costs[i][1] + min(rr, bb);
            b = costs[i][2] + min(rr, gg);
        }
        return min(r, min(g, b));
    }
};

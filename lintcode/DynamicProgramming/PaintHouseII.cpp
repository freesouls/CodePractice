class Solution {
public:
    /**
     * @param costs n x k cost matrix
     * @return an integer, the minimum cost to paint all houses
     */

    int minCostII(vector<vector<int>>& costs) {
        // Write your code here
        if (costs.size() == 0 || costs[0].size() <= 1) {
            return 0;
        }

        int k = costs[0].size();
        int min_a = 0, min_a_index = -1;
        int min_b = 0;//, min_b_index = -1;
        for (int i = 0; i < costs.size(); i++) {
            int tmp_min_a = INT_MAX, tmp_min_a_index = -1;
            int tmp_min_b = INT_MAX;//, tmp_min_b_index = -1;
            for (int j = 0; j < k; j++ ) {
                int cost = costs[i][j];
                if (j != min_a_index) {
                    cost += min_a;
                }
                else {
                    cost += min_b;
                }

                if (cost < tmp_min_a) {
                    tmp_min_b = tmp_min_a;
                    // tmp_min_b_index = tmp_min_a_index;
                    tmp_min_a = cost;
                    tmp_min_a_index = j;
                }
                else if(cost < tmp_min_b) {
                    tmp_min_b = cost;
                    // tmp_min_b_index = j;
                }
            }
            min_a = tmp_min_a;
            min_a_index = tmp_min_a_index;
            min_b = tmp_min_b;
            // min_b_index = tmp_min_b_index;
        }

        return min_a;
    }
};

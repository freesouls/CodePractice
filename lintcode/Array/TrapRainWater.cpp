class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        int max = -1;
        int peak = -1;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] > peak) {
                peak = heights[i];
                max = i;
            }
        }
        int sum = 0;
        peak = 0;
        for (int i = 0; i < max; i++) {
            if (heights[i] > peak) {
                peak = heights[i];
            }
            else{
                sum += peak - heights[i];
            }
        }

        peak = 0;
        for (int i = heights.size() - 1; i > max; i--) {
            if (heights[i] > peak) {
                peak = heights[i];
            }
            else{
                sum += peak - heights[i];
            }
        }
        return sum;
    }
};

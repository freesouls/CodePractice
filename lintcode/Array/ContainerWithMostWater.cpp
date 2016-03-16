class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int i = 0;
        int j = heights.size() - 1;
        int area = 0;
        while( i < j ) {
            area = std::max(area, (j-i)*std::min(heights[i], heights[j]));
            if (heights[i] < heights[j]) {
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};

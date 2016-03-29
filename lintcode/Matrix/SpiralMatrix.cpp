class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return res;
        }

        int beginX = 0;
        int endX = matrix[0].size() - 1;
        int beginY = 0;
        int endY = matrix.size() - 1;
        res.resize((endX+1)*(endY+1));
        int count = 0;

        while(true) {
            for (int i = beginX; i <= endX; i++) {
                res[count++] = matrix[beginY][i];
            }

            if (++beginY > endY){
                break;
            }

            for (int i = beginY; i <= endY; i++) {
                res[count++] = matrix[i][endX];
            }

            if (--endX < beginX) {
                break;
            }

            for (int i = endX; i >= beginX; i--) {
                res[count++] = matrix[endY][i];
            }

            if (--endY < beginY) {
                break;
            }

            for (int i = endY; i >= beginY; i--) {
                res[count++] = matrix[i][beginX];
            }

            if (++beginX > endX) {
                break;
            }
        }
        return res;
    }
};

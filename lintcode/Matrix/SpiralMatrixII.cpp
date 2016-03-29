class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        vector<vector<int>> matrix(n, vector<int>(n, 0));


        int beginX = 0;
        int endX = n - 1;
        int beginY = 0;
        int endY = n - 1;
        int count = 1;

        while(true) {
            for (int i = beginX; i <= endX; i++) {
                matrix[beginY][i] = count++;
            }

            if (++beginY > endY){
                break;
            }

            for (int i = beginY; i <= endY; i++) {
                matrix[i][endX] = count++;
            }

            if (--endX < beginX) {
                break;
            }

            for (int i = endX; i >= beginX; i--) {
                matrix[endY][i] = count++;
            }

            if (--endY < beginY) {
                break;
            }

            for (int i = endY; i >= beginY; i--) {
                matrix[i][beginX] = count++;
            }

            if (++beginX > endX) {
                break;
            }
        }
        return matrix;

    }
};

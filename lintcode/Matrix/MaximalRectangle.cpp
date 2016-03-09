class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        vector<int> height(matrix[0].size(), 0);
        int max_rec = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                height[j] = matrix[i][j] == 1 ? height[j]+1: 0;
            }
            max_rec = max(max_rec, largestRectangleArea(height));
        }
        return max_rec;
    }

    int largestRectangleArea(vector<int> &height) {
        // write your code here
        int max_area = 0;
        stack<int> q;
        int i = 0;
        for(; i < height.size(); i++) {
            while (!q.empty() && height[i] < height[q.top()]) {
                int index = q.top();
                q.pop();
                max_area = max(max_area, height[index]*(q.empty()? i: i - q.top() -1));
            }
            q.push(i);
        }

        while(!q.empty()) {
            int index = q.top();
            q.pop();
            max_area = max(max_area, height[index]*(q.empty()? i: i-q.top()-1));
        }
        return max_area;
    }

};

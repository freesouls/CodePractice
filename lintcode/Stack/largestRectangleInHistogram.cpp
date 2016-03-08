class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */

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

    //TLE
    int largestRectangleArea2(vector<int> &height) {
        // write your code here
        int max_area = 0;
        for(int i = 0; i < height.size(); i++) {
            max_area = max(max_area, get_max(height, i));
        }
        return max_area;
    }

    int get_max(vector<int>& height, int index) {
        int left = index;
        int right = index;

        while(left >= 0 && height[left] >= height[index]) {
            left--;
        }
        left++;

        while(right < height.size() && height[right] >= height[index]) {
            right++;
        }

        right--;

        return height[index]*(right-left + 1);
    }
};

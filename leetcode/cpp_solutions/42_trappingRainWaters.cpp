class Solution {
public:
    int trap(vector<int>& height) {
        int max = -1;
        int peak = -1;
        int n = height.size();
        for(int i = 0; i < n; i++){
            if (height[i] > peak){
                max = i;
                peak = height[i];
            }
        }
        peak = 0;
        int sum = 0;
        for(int i = 0; i < max; i++){
            if (height[i] > peak){
                peak = height[i];
            }
            else{
                sum += peak - height[i];
            }
        }
        peak = 0;
        for(int i = n-1; i > max; i--){
            if (height[i] > peak){
                peak = height[i];
            }
            else{
                sum += peak - height[i];
            }
        }

        return sum;
    }
};

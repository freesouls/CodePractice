class Solution {
public:
    int maxArea(vector<int>& height) {
        int num = height.size();

        int start = 0, end = num - 1;
        int maxarea = (num - 1)*min(height[start], height[end]);
        
        while(start < end){
            if(height[start] <= height[end]){ // can be <
                start++;
            }else{
                end--;
            }
            maxarea = max(maxarea, (end-start)*min(height[start], height[end]));
        }
        return maxarea;
    }
};
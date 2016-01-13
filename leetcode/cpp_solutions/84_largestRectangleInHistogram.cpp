class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        if (n==0){
            return 0;
        }
        
        int res = 0;
        stack<int> s;
        
        for (int i = 0; i < n; i++){
            while(!s.empty() && height[i] < height[s.top()]){
                int tmp = s.top();
                s.pop();
                res = max(res, height[tmp]*(s.empty()? i: (i - s.top() - 1)));
            }
            s.push(i);
        }
        while(!s.empty()){
            int index = s.top();
            s.pop();
            res = max(res, height[index]*(s.empty() ? n : (n - s.top() - 1)));
        }
        return res;
    }
};
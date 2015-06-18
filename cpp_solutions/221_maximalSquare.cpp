class Solution {
public:
    // dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i,j-1])
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        if (m == 1){ // if only one raw, check if there is a 1, then return 1*1 or 0
            for(int j = 0; j < n; j++){
                if (matrix[0][j] == '1'){
                    return 1;
                }
            }
            return 0;
        }
        // matrix has more than two rows
        int* p1 = new int[n]; // dp[i][j] is too large, use two array will suffice, but needs change the pointer after each iteration
        int* p2 = new int[n];
        memset(p1, 0, sizeof(int)*n);
        memset(p2, 0, sizeof(int)*n);
        for(int j = 0; j < n; j++){
            if (matrix[0][j] == '1'){
                p1[j] = 1;
                res = 1;
            }
        }
        
        for (int i = 1; i < m; i++){
            p2[0] = matrix[i][0] - '0';
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == '1'){
                    p2[j] = min(p2[j-1], min(p1[j-1], p1[j])) + 1; 
                    res = max(res, p2[j]);
                }
                else{
                    p2[j] = 0;
                }
            }
            int* tmp = p1;
            p1 = p2;
            p2 = tmp;
        }
        delete[] p1;
        delete[] p2;
        return res*res;
    }

    int maximalSquare2(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m){
            int n = matrix[0].size();
            vector<int> height(n, 0);
            int res = 0;
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    height[j] = matrix[i][j] == '0'? 0: height[j] + 1;
                }
                res = max(res, largestSquareLength(height)); // version 1, comes from problem: Maximal Rectangle Area
                //res = max(res, largestSquareArea(height)); // version 2
            }
            
            return res;
        }
        else{
            return 0;
        }
    }
    
    int largestSquareLength(vector<int>& height) {
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
                res = max(res, min(height[tmp], s.empty()? i: (i - s.top() - 1)));
            }
            s.push(i);
        }
        while(!s.empty()){
            int index = s.top();
            s.pop();
            res = max(res, min(height[index], s.empty()? n: (n - s.top() - 1)));
        }
        return res;
    }

    int largestSquareArea(vector<int>& height) {
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
                int l = min(height[tmp], s.empty()? i: (i - s.top() - 1));
                res = max(res, l*l);
            }
            s.push(i);
        }
        while(!s.empty()){
            int index = s.top();
            s.pop();
            int l = min(height[index], s.empty()? n: (n - s.top() - 1));
            res = max(res, l*l);
        }
        return res;
    }
};
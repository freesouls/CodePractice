class Solution {
public:
    // TO DO iterative version
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n<=0) return res;
        
        vector<int> path;
        combine(res, path, 0, n, k);
        cout << res.size() << endl;
        return res;
    }
    
    void combine(vector<vector<int> >& res, vector<int>& path, int start, int n, int k){
        if (path.size() == k){
            res.push_back(path);
            return;
        }
        for (int j = start + 1; j <= n; j++) {
            path.push_back(j);
            combine(res, path, j, n, k);
            path.pop_back();
        }
    }
};
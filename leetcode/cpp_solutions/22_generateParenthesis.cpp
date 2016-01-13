class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n<=0){
            return res;
        }
        else{
            generate(res, "", 0, 0, n);
        }
    }
    
    void generate(vector<string>& res, string cur, int left, int right, int n){
        if (left == right && left == n){
            res.push_back(cur);
        }
        else{
            if (left < n){
                generate(res, cur+"(", left+1, right, n);
            }
            if (right < left){
                generate(res, cur+")", left, right+1, n);
            }
        }
    }
};
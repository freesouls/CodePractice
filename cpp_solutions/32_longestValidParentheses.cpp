class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len <= 1){
            return 0;
        }
        
        stack<int> q;
        int res = 0;
        int i = 0;
        int last = -1;
      
        while(i < len){
            if(s[i] == ')'){
                if (q.empty()){
                    last = i;
                }
                else{
                    q.pop();
                    if (!q.empty()){
                        res = max(res, i - q.top());
                    }
                    else{
                        res = max(res, i - last);
                    }   
                }
            }
            else{
                q.push(i);
            }
            i++;
        }
        return res;
    }
};
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() > 12){
            return res;
        }
        vector<int> cur;
        restore(res, 0, cur, s);
        return res;
    }

    void restore(vector<string>& res, int index, vector<int>& cur, string& s){
        if (index >= s.size() && cur.size() == 4){
            stringstream ss;
            ss << cur[0] << '.' << cur[1] << '.' << cur[2] << '.' << cur[3];
            res.push_back(ss.str());
        }
        else{
            int tmp = 0;
            for(int i = index; i < s.size(); i++){
                tmp = tmp*10 + s[i] - '0';
                if (tmp < 256){
                    cur.push_back(tmp);
                    restore(res, i + 1, cur, s);
                    cur.pop_back();
                }
                else{
                    break;
                }
                if (tmp == 0){
                    break;
                }
            }
        }
    }
};

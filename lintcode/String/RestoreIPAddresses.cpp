class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> res;
        vector<int> cur;
        dfs(res, s, cur,0);
        return res;
    }

    void dfs(vector<string>& res, string& s, vector<int> & cur, int depth) {
        if (cur.size() > 4) {
            return;
        }
        if (depth == s.length() && cur.size() == 4) {
            string tmp = to_string(cur[0]) + "." + to_string(cur[1]) + "." + to_string(cur[2]) + "." + to_string(cur[3]);
            res.push_back(tmp);
            return;
        }

        int num = 0;
        for (int i = depth; i < s.length(); i++) {
            if (i != depth && s[i-1] == '0' && num == 0) {
                break;
            }
            num = num*10 + s[i] - '0';
            if (num <= 255) {
                cur.push_back(num);
                dfs(res, s, cur, i + 1);
                cur.pop_back();
            }
            else {
                break;
            }
        }
    }
};

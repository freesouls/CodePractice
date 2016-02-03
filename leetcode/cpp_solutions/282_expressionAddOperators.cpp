class Solution {
    vector<string> exps;
    int target_num;
public:
    vector<string> addOperators(string num, int target) {
        target_num = target;
        exps.clear();
        getExpression(num,"", 0, 0);
        return exps;
    }

    void getExpression(string str, string path, long eval, long last_num) {
        if (str.length() == 0) {
            if (eval == target_num) {
                exps.push_back(path);
            }
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            if (i != 0 && str[0] == '0') {
                break;
            }
            string num = str.substr(0, i + 1);
            string right = str.substr(i + 1);
            long cur = stol(num);
            if (path.length() > 0) {
                getExpression(right, path+"-"+num, eval - cur, -cur);
                getExpression(right, path+"+"+num, eval + cur, cur);
                // last_num is the results of several multiplied nums
                getExpression(right, path+"*"+num, eval - last_num + last_num*cur, last_num*cur);

            }
            else {
                getExpression(right, num, cur, cur);
            }
        }

    }
};

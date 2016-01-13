class Solution {
public:
    string countAndSay(int n) {
        string res;
        if (n <= 0){
            return res;
        }
        res = "1";
        for(int i = 1; i < n; i++){
            string tmp;
            char flag = res[0];
            int count = 1;
            int j = 1;
            while(j < res.size()){
                if (res[j] != flag){
                    tmp += to_string(count);
                    tmp += string(1, flag);
                    flag = res[j];
                    count = 1;
                }
                else{
                    count++;
                }
                j++;
            }
            tmp += to_string(count);
            tmp += string(1, flag);
            res = tmp;
        }
        return res;
    }
};

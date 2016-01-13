class Solution {
public:
    bool isHappy(int n) {
        if (n == 0){
            return false;
        }
        vector<int> dic;
        int tmp = n;
        while(1){
            int nn = tmp;
            tmp = 0;
            while(nn){
                int a = nn % 10;
                tmp += a*a;
                nn /= 10;
            }
            
            if (tmp == 1){
                return true;
            }
            
            if (std::find(dic.begin(), dic.end(), tmp) != dic.end()){
                return false;
            }
            else{
                dic.push_back(tmp);
            }
        }
        return false;
    }
};
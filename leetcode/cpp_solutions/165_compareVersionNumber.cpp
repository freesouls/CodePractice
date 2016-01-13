class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1 = 0, num2 = 0;
        int c1 = 1, c2 = 1;
        vector<int> l1, l2;
        for(int i = 0; i < version1.size();i++){
            if (version1[i] != '.'){
                num1 = num1*10 + version1[i] - '0';
            }
            else{
                l1.push_back(num1);
                num1 = 0;
                c1++;
            }
        }
        l1.push_back(num1);

        for(int j = 0; j < version2.size();j++){
            if (version2[j] != '.'){
                num2 = num2*10 + version2[j] - '0';
            }
            else{
                l2.push_back(num2);
                num2 = 0;
                c2++;
            }
        }
        l2.push_back(num2);

        int len = min(c1, c2);
        for (int i = 0; i < len; i++){
            if (l1[i] < l2[i]){
                return -1;
            }
            if (l1[i] > l2[i]){
                return 1;
            }
        }

        if (c1 > c2){
            for(int i = len; i < c1; i++){
                if (l1[i] != 0){
                    return 1;
                }
            }
            return 0;
        }
        if (c1 < c2){
            for(int i = len; i < c2; i++){
                if (l2[i] != 0){
                    return -1;
                }
            }
            return 0;
        }
        return 0;
    }
};
